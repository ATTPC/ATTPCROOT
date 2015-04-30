#include "ATPSASimple2.hh"

// STL
#include <cmath>

ClassImp(ATPSASimple2)

ATPSASimple2::ATPSASimple2()
{
  fPeakFinder = new TSpectrum();
}

ATPSASimple2::~ATPSASimple2()
{
}

void
ATPSASimple2::Analyze(ATRawEvent *rawEvent, ATEvent *event)
{
  Int_t numPads = rawEvent -> GetNumPads();
  Int_t hitNum = 0;
  Double_t QEventTot=0.0;
  

  for (Int_t iPad = 0; iPad < numPads; iPad++) {
    ATPad *pad = rawEvent -> GetPad(iPad);
      Int_t PadNum = pad->GetPadNum();
      Double_t QHitTot = 0.0;
    
    //Double_t xPos = CalculateX(pad -> GetRow()); //Obsolete
    //Double_t zPos = CalculateZ(pad -> GetLayer());
    Double_t xPos = pad -> GetPadXCoord();
    Double_t yPos = pad -> GetPadYCoord();
    Double_t zPos = 0;
    Double_t charge = 0;

    if (!(pad -> IsPedestalSubtracted())) {
      fLogger -> Error(MESSAGE_ORIGIN, "Pedestal should be subtracted to use this class!");

      return;
    }

    Double_t *adc = pad -> GetADC();
    Float_t floatADC[512] = {0};
    Float_t dummy[512] = {0};
      for (Int_t iTb = 0; iTb < fNumTbs; iTb++){
          floatADC[iTb] = adc[iTb];
          QHitTot+=adc[iTb];
      }
      
    Int_t numPeaks = fPeakFinder -> SearchHighRes(floatADC, dummy, fNumTbs, 4.7, 5, kFALSE, 3, kTRUE, 3);

    if (numPeaks == 0)
      continue;

    for (Int_t iPeak = 0; iPeak < numPeaks; iPeak++) {
      Int_t maxAdcIdx = (Int_t)(ceil((fPeakFinder -> GetPositionX())[iPeak]));

      zPos = CalculateZ(maxAdcIdx);
      charge = adc[maxAdcIdx];
        //std::cout<<zPos<<std::endl;

      if (fThreshold > 0 && charge < fThreshold) // TODO: Does this work when the polarity is negative??
        continue;

      //if (zPos > 0 || zPos < -fMaxDriftLength)
      if (zPos < 0 || zPos > fMaxDriftLength)
        continue;
        
    
      if(iPeak=0) QEventTot+=QHitTot; //Sum only if Hit is valid - We only sum once to account for the whole spectrum.

      ATHit *hit = new ATHit(PadNum,hitNum, xPos, yPos, zPos, charge);
      hit->SetQHit(QHitTot); // TODO: The charge of each hit is the total charge of the spectrum, so for double structures this is unrealistic.
      
      event -> AddHit(hit);
      delete hit;

      hitNum++;
    }// Peak loop
     
  }// Pad loop
    
     event -> SetEventCharge(QEventTot);
}
