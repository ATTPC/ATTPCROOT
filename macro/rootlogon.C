void rootlogon(){
gROOT->SetStyle("Plain");
gStyle->SetPalette(1);
gStyle->SetPadColor(0);
gStyle->SetDrawBorder(0);
gStyle->SetPadBorderSize(2);
gStyle->SetPadBorderMode(1);
gStyle->SetPadBottomMargin(.15);
gStyle->SetPadLeftMargin(.15);
gStyle->SetOptStat(1111111);
gStyle->SetLabelSize(0.06,"X");
gStyle->SetLabelSize(0.06,"Y");
gStyle->SetTitleSize(0.06,"X");
gStyle->SetTitleSize(0.06,"Y");
gStyle->SetTitleOffset(1.22,"X");
gStyle->SetTitleOffset(1.22,"Y");
gStyle->SetNdivisions(505,"X");
gStyle->SetNdivisions(505,"Y");
gStyle->SetMarkerColor(2);
//TStyle *sty=black();
//gROOT->SetStyle("black");
//use this for piffia

//printf("\nWelcome to the PIFFIA Root environment\n\n");
//if(!gROOT->LoadMacro("/home/fpfaneca/david/Thesis/test/Chain.C"))
//if(!gROOT->LoadMacro("/home/fpfaneca/david/bin/Chain.C"))
//   cout<<"Macro Chain.C successfully loaded"<<endl;
set_plot_style();
gErrorIgnoreLevel=2001;
}

void set_plot_style()
{
    const Int_t NRGBs = 5;
    const Int_t NCont = 255;

    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    //    if(gROOT->GetVersionInt()!=52400)
    //  gStyle->CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    //else
      TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
      
    gStyle->SetNumberContours(NCont);
}

