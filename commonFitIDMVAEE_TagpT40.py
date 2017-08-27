import FWCore.ParameterSet.Config as cms

all_pdfs = cms.PSet(
passingIDMVA_0p0To0p9_1p479To2p5 = cms.vstring(
"RooGaussian::signalResPass(mass, meanP[1.0,-5.000,5.000],sigmaP[1.5,0.001,5.000])",
"RooGaussian::signalResFail(mass, meanF[1.0,-5.000,5.000],sigmaF[0.5,0.001,5.000])",
"ZGeneratorLineShape::signalPhyPass(mass,\"templateIDMVAEE_NewLowmassTransfmTagpT40.root\", \"hMass_0.0To0.9_1.479To2.5_Pass\")",
"ZGeneratorLineShape::signalPhyFail(mass,\"templateIDMVAEE_NewLowmassTransfmTagpT40.root\", \"hMass_0.0To0.9_1.479To2.5_Fail\")",
"RooCMSShape::backgroundPass(mass, alphaPass[66.05,50.,70.], betaPass[0.05, 0.,0.1], gammaPass[0.04, 0, 1], peakPass[90.0, 70, 80])",
"RooCMSShape::backgroundFail(mass, alphaFail[59.95,50.,70.], betaFail[0.001, 0.,0.1], gammaFail[0.1, 0, 1], peakFail[90.0, 70, 80])",
"FCONV::signalPass(mass, signalPhyPass, signalResPass)",
"FCONV::signalFail(mass, signalPhyFail, signalResFail)",
"efficiency[0.5,0,1]",
"signalFractionInPassing[1.0]"
),

passingIDMVA_0p9To1p0_1p479To2p5 = cms.vstring(
"RooGaussian::signalResPass(mass, meanP[1.0,-5.000,5.000],sigmaP[0.5,0.001,5.000])",
"RooGaussian::signalResFail(mass, meanF[1.0,-5.000,5.000],sigmaF[0.5,0.05,5.000])",
"ZGeneratorLineShape::signalPhyPass(mass,\"templateIDMVAEE_NewLowmassTransfmTagpT40.root\", \"hMass_0.9To1.0_1.479To2.5_Pass\")",
"ZGeneratorLineShape::signalPhyFail(mass,\"templateIDMVAEE_NewLowmassTransfmTagpT40.root\", \"hMass_0.9To1.0_1.479To2.5_Fail\")",
"RooCMSShape::backgroundPass(mass, alphaPass[63.76,50.,75.], betaPass[0.04, 0.,0.1], gammaPass[0.04, 0, 1], peakPass[90.0, 70, 80])",
"RooCMSShape::backgroundFail(mass, alphaFail[55.7265,50.,75.], betaFail[0.05, 0.,0.1], gammaFail[0.01, 0, 1], peakFail[90.0, 70, 80])",
"FCONV::signalPass(mass, signalPhyPass, signalResPass)",
"FCONV::signalFail(mass, signalPhyFail, signalResFail)",
"efficiency[0.5,0,1]",
"signalFractionInPassing[1.0]"
),

)
