#####################################################################
#This file is an event dumper for preselection and IDMVA Efficiency
#study in Low mass Higgs to diphoton analysis. Created from 
#makeTreePhoton.py by Arnab Purohit in 2017.
#####################################################################

import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing
import sys

process = cms.Process("tnp")

###################################################################
myoptions = dict()
isMC = True
#isMC = False
myoptions['HLTProcessName']        = "HLT"

myoptions['DIPHOTON_COLL']         = "flashggDiPhotonSystematics"
myoptions['PHOTON_CUTS']           = "(abs(superCluster.eta)<2.5) && ((superCluster.energy*sin(superCluster.position.theta))>18.0)&& !(1.4442<=abs(superCluster.eta)<=1.566)"
myoptions['PHOTON_TAG_CUTS']       = "(abs(superCluster.eta)<=2.5) && !(1.4442<=abs(superCluster.eta)<=1.566) && (superCluster.energy*sin(superCluster.position.theta))>30.0"
myoptions['MAXEVENTS']             = cms.untracked.int32(-1) 
myoptions['useAOD']                = cms.bool(False)
myoptions['OUTPUTEDMFILENAME']     = 'edmFile.root'
myoptions['DEBUG']                 = cms.bool(False)
#############################################################################
#Preselection cuts are applied in the following lines first for leading then 
#for subleading Photons
#############################################################################

myoptions['LEADING_PRESELECTION']  = """(abs(leadingPhoton.superCluster.eta) < 2.5 && abs(subLeadingPhoton.superCluster.eta) < 2.5) && 
                                      ( (abs(leadingPhoton.superCluster.eta) < 1.4442 && abs(subLeadingPhoton.superCluster.eta) < 1.4442) || (abs(leadingPhoton.superCluster.eta) < 1.4442 && leadingPhoton.full5x5_r9>0.85 && abs(subLeadingPhoton.superCluster.eta) > 1.566 && subLeadingPhoton.full5x5_r9>0.90 ) || (abs(leadingPhoton.superCluster.eta) > 1.566 && leadingPhoton.full5x5_r9>0.90 && abs(subLeadingPhoton.superCluster.eta) < 1.4442 && subLeadingPhoton.full5x5_r9>0.85) || (abs(leadingPhoton.superCluster.eta) > 1.566 && leadingPhoton.full5x5_r9>0.90 && abs(subLeadingPhoton.superCluster.eta) > 1.566 && subLeadingPhoton.full5x5_r9>0.90 ) ) &&
                                        (leadingPhoton.pt > 30) &&
                                        ((leadingPhoton.full5x5_r9 > 0.5 && leadingPhoton.isEB) || (leadingPhoton.full5x5_r9 > 0.8 && leadingPhoton.isEE)) &&
                                        ((subLeadingPhoton.full5x5_r9 > 0.5 && subLeadingPhoton.isEB) || (subLeadingPhoton.full5x5_r9 > 0.8 && subLeadingPhoton.isEE)) &&
                                        ((leadingPhoton.isEB && (leadingPhoton.hadronicOverEm < 0.07) &&
                                        ((leadingPhoton.full5x5_r9>0.85 && leadingPhoton.full5x5_sigmaIetaIeta < 0.0105 && leadingPhoton.pfPhoIso03 < 4.0 && leadingPhoton.trkSumPtHollowConeDR03 < 6.0) ||
                                        (leadingPhoton.full5x5_r9<0.85 && leadingPhoton.full5x5_sigmaIetaIeta < 0.0105 && leadingPhoton.pfPhoIso03 < 4.0 && leadingPhoton.trkSumPtHollowConeDR03 < 6.0 ))) ||
                                        (leadingPhoton.isEE && (leadingPhoton.hadronicOverEm < 0.035) &&
                                        ((leadingPhoton.full5x5_r9>0.9 && leadingPhoton.full5x5_sigmaIetaIeta < 0.0275 && leadingPhoton.pfPhoIso03 < 4.0 && leadingPhoton.trkSumPtHollowConeDR03 < 6.0) ||
                                        (leadingPhoton.full5x5_r9<0.9 && leadingPhoton.full5x5_sigmaIetaIeta < 0.0 && leadingPhoton.pfPhoIso03 < 0.0 && leadingPhoton.trkSumPtHollowConeDR03 < 0.0 )))) &&
                                        (leadingPhoton.pt > 14 && leadingPhoton.hadTowOverEm()<0.15 &&
                                        (leadingPhoton.full5x5_r9()>0.8 || leadingPhoton.chargedHadronIso()<20 || leadingPhoton.chargedHadronIso()<0.3*leadingPhoton.pt())) 
""" 

myoptions['SUBLEADING_PRESELECTION'] = """(abs(leadingPhoton.superCluster.eta) < 2.5 && abs(subLeadingPhoton.superCluster.eta) < 2.5) &&
                                        ( (abs(leadingPhoton.superCluster.eta) < 1.4442 && abs(subLeadingPhoton.superCluster.eta) < 1.4442) || (abs(leadingPhoton.superCluster.eta) < 1.4442 && leadingPhoton.full5x5_r9>0.85 && abs(subLeadingPhoton.superCluster.eta) > 1.566 && subLeadingPhoton.full5x5_r9>0.90 ) || (abs(leadingPhoton.superCluster.eta) > 1.566 && leadingPhoton.full5x5_r9>0.90 && abs(subLeadingPhoton.superCluster.eta) < 1.4442 && subLeadingPhoton.full5x5_r9>0.85) || (abs(leadingPhoton.superCluster.eta) > 1.566 && leadingPhoton.full5x5_r9>0.90 && abs(subLeadingPhoton.superCluster.eta) > 1.566 && subLeadingPhoton.full5x5_r9>0.90 ) ) &&
                                        (subLeadingPhoton.pt > 18) && 
                                        ((leadingPhoton.full5x5_r9 > 0.5 && leadingPhoton.isEB) || (leadingPhoton.full5x5_r9 > 0.8 && leadingPhoton.isEE)) &&
                                        ((subLeadingPhoton.full5x5_r9 > 0.5 && subLeadingPhoton.isEB) || (subLeadingPhoton.full5x5_r9 > 0.8 && subLeadingPhoton.isEE)) &&
                                        ((subLeadingPhoton.isEB && (subLeadingPhoton.hadronicOverEm < 0.07) && 
                                        ((subLeadingPhoton.full5x5_r9>0.85 && subLeadingPhoton.full5x5_sigmaIetaIeta < 0.0105 && subLeadingPhoton.pfPhoIso03 < 4.0 && subLeadingPhoton.trkSumPtHollowConeDR03 < 6.0) ||
                                        (subLeadingPhoton.full5x5_r9<0.85 && subLeadingPhoton.full5x5_sigmaIetaIeta < 0.0105 && subLeadingPhoton.pfPhoIso03 < 4.0 && subLeadingPhoton.trkSumPtHollowConeDR03 < 6.0 ))) ||
                                        (subLeadingPhoton.isEE && (subLeadingPhoton.hadronicOverEm < 0.035) && 
                                        ((subLeadingPhoton.full5x5_r9>0.9 && subLeadingPhoton.full5x5_sigmaIetaIeta < 0.0275 && subLeadingPhoton.pfPhoIso03 < 4.0 && subLeadingPhoton.trkSumPtHollowConeDR03 < 6.0) ||
                                        (subLeadingPhoton.full5x5_r9<0.9 && subLeadingPhoton.full5x5_sigmaIetaIeta < 0.0 && subLeadingPhoton.pfPhoIso03 < 0.0 && subLeadingPhoton.trkSumPtHollowConeDR03 < 0.0 )))) &&
                                        (subLeadingPhoton.pt > 14 && subLeadingPhoton.hadTowOverEm()<0.15 &&
                                        (subLeadingPhoton.full5x5_r9()>0.8 || subLeadingPhoton.chargedHadronIso()<20 || subLeadingPhoton.chargedHadronIso()<0.3*subLeadingPhoton.pt()))
"""


from flashgg.Validation.treeMakerOptionsPhotons_cfi import *

if (isMC):
    myoptions['INPUT_FILE_NAME']       = ("/store/group/phys_higgs/cmshgg/ferriff/flashgg/RunIIFall15DR76-1_3_0-25ns_ext1/1_3_1/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIIFall15DR76-1_3_0-25ns_ext1-1_3_1-v0-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/160127_112132/0000/myMicroAODOutputFile_9.root")

    myoptions['OUTPUT_FILE_NAME']      = "TnPTree_mc.root"
    myoptions['TnPPATHS']              = cms.vstring("HLT_Ele27_WPTight_Gsf_v*")###Change the HLT path for MC accordingly
    myoptions['TnPHLTTagFilters']      = cms.vstring("hltEle27WPTightGsfTrackIsoFilter")                        
    myoptions['TnPHLTProbeFilters']    = cms.vstring()
    myoptions['HLTFILTERTOMEASURE']    = cms.vstring("")
    myoptions['GLOBALTAG']             = '80X_mcRun2_asymptotic_2016_TrancheIV_v6' ###Choose correct Global tag for MC here
    myoptions['EVENTSToPROCESS']       = cms.untracked.VEventRange()
else:
    myoptions['INPUT_FILE_NAME']       = ("/store/group/phys_higgs/cmshgg/ferriff/flashgg/RunIIFall15DR76-1_3_0-25ns_ext1/1_3_1/SingleElectron/RunIIFall15DR76-1_3_0-25ns_ext1-1_3_1-v0-Run2015D-16Dec2015-v1/160127_024003/0000/myMicroAODOutputFile_10.root")
    myoptions['OUTPUT_FILE_NAME']      = "TnPTree_data.root"
    myoptions['TnPPATHS']              = cms.vstring("HLT_Ele27_WPTight_Gsf_v*")###Change the HLT path for data accordingly
    myoptions['TnPHLTTagFilters']      = cms.vstring("hltEle27WPTightGsfTrackIsoFilter")
    myoptions['TnPHLTProbeFilters']    = cms.vstring()
    myoptions['HLTFILTERTOMEASURE']    = cms.vstring("")
    myoptions['GLOBALTAG']             = '80X_dataRun2_2016SeptRepro_v3' ###Choose correct Global tag for MC here
    myoptions['EVENTSToPROCESS']       = cms.untracked.VEventRange()

###################################################################

setModules(process, myoptions)
###################################################################
#If some variables needs to be added in the tree please add them in
#the following module treeContentPhotons_cfi.py in python directory
###################################################################
from flashgg.Validation.treeContentPhotons_cfi import *

process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")
process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.GlobalTag.globaltag = myoptions['GLOBALTAG']

process.load('FWCore.MessageService.MessageLogger_cfi')
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) )

process.MessageLogger.cerr.threshold = ''
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(myoptions['INPUT_FILE_NAME']),
                            eventsToProcess = myoptions['EVENTSToPROCESS']
                            )

process.maxEvents = cms.untracked.PSet( input = myoptions['MAXEVENTS'])

###################################################################
## ID
###################################################################

from flashgg.Validation.photonIDModules_cfi import *
setIDs(process, myoptions)

###################################################################
## SEQUENCES
###################################################################

process.egmPhotonIDs.physicsObjectSrc = cms.InputTag("photonFromDiPhotons")

process.pho_sequence = cms.Sequence(
    process.photonFromDiPhotons +
    process.goodPhotonTags +
    process.goodPhotonProbes +
    process.goodPhotonProbesPreselection +
    process.goodPhotonProbesIDMVA +
    process.goodPhotonTagsIDMVA +
    process.goodPhotonsTagHLT +
    process.goodPhotonsProbeHLT  +
    process.goodPhotonProbesL1
    )

###################################################################
## TnP PAIRS
###################################################################

process.allTagsAndProbes = cms.Sequence()
process.allTagsAndProbes *= process.tagTightRECO

process.mc_sequence = cms.Sequence()

##########################################################################
## TREE MAKER OPTIONS
##########################################################################
if (not isMC):
    mcTruthCommonStuff = cms.PSet(
        isMC = cms.bool(False)
        )
    
process.PhotonToRECO = cms.EDAnalyzer("TagProbeFitTreeProducer",
                                      mcTruthCommonStuff, CommonStuffForPhotonProbe,
                                      tagProbePairs = cms.InputTag("tagTightRECO"),
                                      arbitration   = cms.string("None"),
                                      flags         = cms.PSet(passingPresel  = cms.InputTag("goodPhotonProbesPreselection"),
                                                               passingIDMVA   = cms.InputTag("goodPhotonProbesIDMVA"),
                                                               ),                                               
                                      allProbes     = cms.InputTag("goodPhotonsProbeHLT"),
                                      )

if (isMC):
    #process.PhotonToRECO.probeMatches  = cms.InputTag("McMatchRECO")
    process.PhotonToRECO.eventWeight   = cms.InputTag("generator")
    process.PhotonToRECO.PUWeightSrc   = cms.InputTag("pileupReweightingProducer","pileupWeights")
    

process.tree_sequence = cms.Sequence(process.PhotonToRECO)

##########################################################################
## PATHS
##########################################################################

process.out = cms.OutputModule("PoolOutputModule", 
                               fileName = cms.untracked.string(myoptions['OUTPUTEDMFILENAME']),
                               SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring("p"))
                               )
process.outpath = cms.EndPath(process.out)
if (not myoptions['DEBUG']):
    process.outpath.remove(process.out)

##########################################################################################
###### MICROAOD STUFF
##########################################################################################
process.load("flashgg/Taggers/flashggUpdatedIdMVADiPhotons_cfi")
process.flashggUpdatedIdMVADiPhotons.DiPhotonTag = cms.InputTag('flashggDiPhotons') #To include shower shape and other corrections 
process.load("flashgg/Taggers/flashggDiPhotonMVA_cfi")
process.flashggDiPhotonMVA.DiPhotonTag = cms.InputTag('flashggDiPhotonSystematics')
 
##########################################################################################
#       Systematics       
##########################################################################################
## import systs. customize
from flashgg.Systematics.SystematicsCustomize import *

doUpdatedIdMVADiPhotons = False
## apply shower shape corrections for MC
if(isMC):
    doUpdatedIdMVADiPhotons = True # Set to True for MC only. Default value is False (for data)

## load syst producer
process.load("flashgg.Systematics.flashggDiPhotonSystematics_cfi")

if (doUpdatedIdMVADiPhotons):
    process.flashggDiPhotonSystematics.src = "flashggUpdatedIdMVADiPhotons"
else:
    process.flashggDiPhotonSystematics.src = "flashggDiPhotons"
print "input to flashggDiPhotonSystematics = ", process.flashggDiPhotonSystematics.src

## Or use the official  tool instead  ????????????????
useEGMTools(process)

## if data, apply only energy scale corrections, if MC apply only energy smearings
if (not isMC):
    print 'data' 
    customizePhotonSystematicsForData(process)    # only central value, no syst. shifts 
else:
    print 'mc'
    customizePhotonSystematicsForMC(process)
    ##syst (1D) 
    vpset   = process.flashggDiPhotonSystematics.SystMethods
    newvpset = cms.VPSet()
    for pset in vpset:
        pset.NSigmas = cms.vint32() # no up/down syst shifts
        pset.ApplyCentralValue = cms.bool(False) # no central value
        if ( pset.Label.value().count("MCSmear") or pset.Label.value().count("SigmaEOverESmearing")):
            pset.ApplyCentralValue = cms.bool(True)
        newvpset+= [pset]
    process.flashggDiPhotonSystematics.SystMethods = newvpset        
    ##syst (2D) : smearings with EGMTool
    vpset2D   = process.flashggDiPhotonSystematics.SystMethods2D
    newvpset2D = cms.VPSet()
    for pset in vpset2D:
        pset.NSigmas = cms.PSet( firstVar = cms.vint32(), secondVar = cms.vint32() ) # only central value, no up/down syst shifts (2D case)
        if ( pset.Label.value().count("MCSmear") or pset.Label.value().count("SigmaEOverESmearing")):
            pset.ApplyCentralValue = cms.bool(True)
            newvpset2D+= [pset]
    process.flashggDiPhotonSystematics.SystMethods2D = newvpset2D       
############################
#    Systematics end       #
############################


if (isMC):
    process.p = cms.Path(
        process.flashggUpdatedIdMVADiPhotons +
        process.flashggDiPhotonSystematics+
        process.flashggDiPhotonMVA +
        process.sampleInfo +
        process.hltFilter +
        process.pho_sequence + 
        process.allTagsAndProbes +
        process.pileupReweightingProducer +
        process.mc_sequence + 
        process.tree_sequence
        )
else:
    process.p = cms.Path(
        process.flashggUpdatedIdMVADiPhotons +
        process.flashggDiPhotonSystematics+
        process.flashggDiPhotonMVA +
        #process.sampleInfo +
        process.hltFilter +
        process.pho_sequence + 
        process.allTagsAndProbes +
        process.pileupReweightingProducer +
        process.mc_sequence +
        process.tree_sequence
        )

process.TFileService = cms.Service("TFileService", 
                                   #fileName = cms.string(myoptions['OUTPUT_FILE_NAME']),
                                   fileName = cms.string("TnP.root"),
                                   closeFileFast = cms.untracked.bool(True)
                                   )

from flashgg.MetaData.JobConfig import JobConfig

customize = JobConfig(crossSections=["$CMSSW_BASE/src/flashgg/MetaData/data/cross_sections.json"])
customize.setDefault("maxEvents", -1)
customize.setDefault("targetLumi", 1)
customize(process)

