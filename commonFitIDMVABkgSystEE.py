import FWCore.ParameterSet.Config as cms

all_pdfs = cms.PSet(
passingIDMVA_0p0To0p9_1p479To2p5 = cms.vstring(
"RooGaussian::signalResPass(mass, meanP[1.0,-5.000,5.000],sigmaP[1.5,0.001,5.000])",
"RooGaussian::signalResFail(mass, meanF[1.0,-5.000,5.000],sigmaF[0.5,0.001,5.000])",
"ZGeneratorLineShape::signalPhyPass(mass,\"templateIDMVAEE_NewLowmassTransfm.root\", \"hMass_0.0To0.90_1.479To2.5_Pass\")",
"ZGeneratorLineShape::signalPhyFail(mass,\"templateIDMVAEE_NewLowmassTransfm.root\", \"hMass_0.0To0.90_1.479To2.5_Fail\")",
"RooBernstein::backgroundPass(mass,{a0P[11.70,-20.0,20.0],a1P[10.58,-15.0,15.0],a2P[0.93,-5.0,5.0],a3P[0.05,-0.2,0.2]})",
"RooBernstein::backgroundFail(mass,{a0F[14.61,-20.0,20.0],a1F[4.05,-15.0,15.0],a2F[2.83,-5.0,5.0],a3F[0.18,-0.3,0.3]})",
"FCONV::signalPass(mass, signalPhyPass, signalResPass)",
"FCONV::signalFail(mass, signalPhyFail, signalResFail)",
"efficiency[0.5,0,1]",
"signalFractionInPassing[1.0]"
),

passingIDMVA_0p9To1p0_1p479To2p5 = cms.vstring(
"RooGaussian::signalResPass(mass, meanP[1.0,-5.000,5.000],sigmaP[0.5,0.001,5.000])",
"RooGaussian::signalResFail(mass, meanF[1.0,-5.000,5.000],sigmaF[0.5,0.05,5.000])",
"ZGeneratorLineShape::signalPhyPass(mass,\"templateIDMVAEE_NewLowmassTransfm.root\", \"hMass_0.90To1.0_1.479To2.5_Pass\")",
"ZGeneratorLineShape::signalPhyFail(mass,\"templateIDMVAEE_NewLowmassTransfm.root\", \"hMass_0.90To1.0_1.479To2.5_Fail\")",
"RooBernstein::backgroundPass(mass,{a0P[7.0,0.0,20.0],a1P[0.035,0.0,15.0],a2P[0.0175,-0.3,0.3],a3P[0.0,-0.1,0.1]})",
"RooBernstein::backgroundFail(mass,{a0F[6.8,0.0,20.0],a1F[0.035,0.0,15.0],a2F[0.0175,-0.3,0.3],a3F[0.0,-0.1,0.1]})",
"FCONV::signalPass(mass, signalPhyPass, signalResPass)",
"FCONV::signalFail(mass, signalPhyFail, signalResFail)",
"efficiency[0.5,0,1]",
"signalFractionInPassing[1.0]"
),

)
