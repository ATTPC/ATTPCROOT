// =================================================
//  GETPlot Class
// 
//  Author:
//    Genie Jhang ( geniejhang@majimak.com )
//  
//  Log:
//    - 2013. 10. 01
//      Start writing class
// =================================================

#ifndef _GETPLOT_H_
#define _GETPLOT_H_

#include "TObject.h"

class GETDecoder;
class GETFrame;
class TCanvas;
class TGraph;
class TH2D;
class TPad;
class TText;

/**
  * GETPlot class for drawing various fundamental plots fast typing short command.
 **/
class GETPlot : public TObject
{
  public:
    //! Constructor
    GETPlot();
    //! Construct with GETDecoder pointer
    GETPlot(GETDecoder *decoder);
    //! Destructor
    virtual ~GETPlot();

    //! Set the decoder pointer.
    void SetDecoder(GETDecoder *decoder);

    //! Set the plotting range.
    void SetAgetRange(Int_t type, Int_t agetIdx, Double_t minx, Double_t maxx, Double_t miny, Double_t maxy);
    //! Set FPN sigma threshold
    void SetFPNThreshold(Double_t sigma);

    //! Draw the summary spectra of the file set to the decoder, and return the canvas.
    TCanvas *ShowSummarySpectra(Int_t startTb = 10,  /// Starting time bucket index
                                Int_t numTbs = 20,   /// The number of time buckets from startTb in order to calculate pedestal value
                                Int_t notConnected = 35, /// The number of not-connected channel
                                Int_t innerFrame = 0 /// The number of inner frame when the frame is merged frame
                               );
    //! Draw raw signals in the frame whose number is frameNo.
    TCanvas *ShowRawFrame(Int_t frameNo = -1, Int_t innerFrameNo = -1, Int_t numChannels = 0, Int_t *chList = NULL);
    //! Draw pedestal-subtracted signals in the frame whose number is frameNo.
    TCanvas *ShowFrame(Int_t frameNo = -1, Int_t innerFrameNo = -1, Int_t startTb = 10, Int_t numTbs = 20, Int_t numChannels = 0, Int_t *chList = NULL);
    //! Draw averaged-raw signals in the frame whose number is frameNo.
    TCanvas *ShowAverage(Int_t numChannels, Int_t *chList, Int_t frameNo = -1, Int_t innerFrameNo = 0);
    //! Print Maximum values
    TCanvas *PrintMax(Int_t eventNo, Int_t innerFrameNo, Int_t startTb, Int_t numTbs);

  private:
    //! Initialize variables.
    void Initialize();

    Int_t fMinTb; /// minimum time bucket index for drawing
    Int_t fMaxTb; /// maximum time bucket index for drawing

    Double_t fFPNThreshold; /// FPN sigma threshold

    GETDecoder *fDecoder; /// decoder pointer
    GETFrame *fFrame;     /// frame container pointer

    //! Internal method to prepare canvases
    TCanvas *PrepareCanvas(Int_t type);
    //! Internal method to reset canvases
    void ResetGraph(Int_t type, Bool_t first = 0);
    //! Internal method to print information on canvas
    void PrintInfo(Int_t type, TPad *namePad, Int_t coboIdx, Int_t asadIdx, Int_t frameNo, Int_t eventNo);

    TH2D *fAsad;      /// histogram for summary spectra of an AsAd
    TGraph *fGraph;   /// graph for various purpose for drawing data
    TGraph *fAget[4]; /// graph for each AGET

    Double_t fAgetMinX[4][4]; /// minimum x value for drawing
    Double_t fAgetMaxX[4][4]; /// maximum x value for drawing
    Double_t fAgetMinY[4][4]; /// minimum y value for drawing
    Double_t fAgetMaxY[4][4]; /// maximum y value for drawing

  ClassDef(GETPlot, 1); /// added for making dictionary by ROOT
};

#endif
