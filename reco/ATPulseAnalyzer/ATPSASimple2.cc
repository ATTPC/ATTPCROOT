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

  for (Int_t iPad = 0; iPad < numPads; iPad++) {
    ATPad *pad = rawEvent -> GetPad(iPad);
    
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
    for (Int_t iTb = 0; iTb < fNumTbs; iTb++)
      floatADC[iTb] = adc[iTb];

    Int_t numPeaks = fPeakFinder -> SearchHighRes(floatADC, dummy, fNumTbs, 4.7, 5, kFALSE, 3, kTRUE, 3);

    if (numPeaks == 0)
      continue;

    for (Int_t iPeak = 0; iPeak < numPeaks; iPeak++) {
      Int_t maxAdcIdx = (Int_t)(ceil((fPeakFinder -> GetPositionX())[iPeak]));

      zPos = CalculateZ(maxAdcIdx);
      charge = adc[maxAdcIdx];

      if (fThreshold > 0 && charge < fThreshold)
        continue;

      if (zPos > 0 || zPos < -fMaxDriftLength)
        continue;

      ATHit *hit = new ATHit(hitNum, xPos, yPos, zPos, charge);
      event -> AddHit(hit);
      delete hit;

      hitNum++;
    }
  }
}
