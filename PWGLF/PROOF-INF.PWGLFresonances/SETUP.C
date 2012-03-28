Int_t SETUP()
{
 
   // Load the PWGLFresonances library
   TString dypath = TString::Format("%s:%s", gSystem->WorkingDirectory(), gSystem->GetDynamicPath());
   gSystem->SetDynamicPath(dypath);
   
   if (gSystem->Load("libPWGLFresonances")<0) return -1;

   // Set the include paths
   gROOT->ProcessLine(".include PWGLFresonances");
   gROOT->ProcessLine(".include PWGLFresonances/RESONANCES");

   // Set our location, so that other packages can find us
   gSystem->Setenv("PWGLFresonances_INCLUDE", "PWGLFresonances/RESONANCES");

   // Set our lib coordinates, so that other packages can link to us
   TString lib = TString::Format("-L%s -lPWGLFresonances", gSystem->WorkingDirectory());
   gSystem->Setenv("PWGLFresonances_LIBS", lib.Data());
   
   return 0;
   
}
