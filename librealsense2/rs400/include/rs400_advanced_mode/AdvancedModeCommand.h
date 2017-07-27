/**
 * @file   AdvancedModeCommand.h
 * @brief  Advanced Mode Commands header file
 */

#ifndef ADVANCED_MODE_COMMAND_H
#define ADVANCED_MODE_COMMAND_H

#define ADVANCED_MODE_VER_MAJOR     1
#define ADVANCED_MODE_VER_MINOR     1
#define ADVANCED_MODE_VERSION_ID    (ADVANCED_MODE_VER_MAJOR << 8) | ADVANCED_MODE_VER_MINOR

typedef enum
{
    etDepthControl              = 0,
    etRsm                       = 1,
    etRauSupportVectorControl   = 2,
    etColorControl              = 3,
    etRauColorThresholdsControl = 4,
    etSloColorThresholdsControl = 5,
    etSloPenaltyControl         = 6,
    etHdad                      = 7,
    etColorCorrection           = 8,
    etDepthTableControl         = 9,
    etAEControl                 = 10,
    etCencusRadius9             = 11,
    etLastAdvancedModeGroup     = 12,       // Must be last
}
EtAdvancedModeRegGroup;

typedef enum
{
    etAVCGetCurrent = 0,
    etAVCGetMin,
    etAVCGetMax,
    etColorStep,
}
EtAdvancedModeCommandGetType;

typedef struct
{
    uint32_t plusIncrement;
    uint32_t minusDecrement;
    uint32_t deepSeaMedianThreshold;
    uint32_t scoreThreshA;
    uint32_t scoreThreshB;
    uint32_t textureDifferenceThreshold;
    uint32_t textureCountThreshold;
    uint32_t deepSeaSecondPeakThreshold;
    uint32_t deepSeaNeighborThreshold;
    uint32_t lrAgreeThreshold;
}STDepthControlGroup;


typedef struct
{
    uint32_t rsmBypass;
    float diffThresh;
    float sloRauDiffThresh;
    uint32_t removeThresh;
}STRsm;

typedef struct
{
    uint32_t minWest;
    uint32_t minEast;
    uint32_t minWEsum;
    uint32_t minNorth;
    uint32_t minSouth;
    uint32_t minNSsum;
    uint32_t uShrink;
    uint32_t vShrink;
}STRauSupportVectorControl;

typedef struct
{
    uint32_t disableSADColor;
    uint32_t disableRAUColor;
    uint32_t disableSLORightColor;
    uint32_t disableSLOLeftColor;
    uint32_t disableSADNormalize;
}STColorControl;

typedef struct
{
    uint32_t rauDiffThresholdRed;
    uint32_t rauDiffThresholdGreen;
    uint32_t rauDiffThresholdBlue;
}STRauColorThresholdsControl;

typedef struct
{
    uint32_t diffThresholdRed;
    uint32_t diffThresholdGreen;
    uint32_t diffThresholdBlue;
}STSloColorThresholdsControl;

typedef struct
{
    uint32_t sloK1Penalty;
    uint32_t sloK2Penalty;
    uint32_t sloK1PenaltyMod1;
    uint32_t sloK2PenaltyMod1;
    uint32_t sloK1PenaltyMod2;
    uint32_t sloK2PenaltyMod2;
}STSloPenaltyControl;


typedef struct
{
    float lambdaCensus;
    float lambdaAD;
    uint32_t ignoreSAD;
}STHdad;

typedef struct
{
    float colorCorrection1;
    float colorCorrection2;
    float colorCorrection3;
    float colorCorrection4;
    float colorCorrection5;
    float colorCorrection6;
    float colorCorrection7;
    float colorCorrection8;
    float colorCorrection9;
    float colorCorrection10;
    float colorCorrection11;
    float colorCorrection12;
}STColorCorrection;

typedef struct
{
    uint32_t meanIntensitySetPoint;
}STAEControl;


typedef struct
{
    uint32_t depthUnits;
    int32_t depthClampMin;
    int32_t depthClampMax;
    uint32_t disparityMode;
    int32_t disparityShift;
}STDepthTableControl;


typedef struct
{
    uint32_t uDiameter;
    uint32_t vDiameter;
}STCensusRadius;

#ifndef R400_ADVANCED_MODE_HPP
ErrorTypes AdvancedModeCommandGet( TOpcodeParams* pParams );
ErrorTypes AdvancedModeCommandSet( TOpcodeParams* pParams );
uint16_t AdvancedModeVersionGet();

#endif


#ifdef __cplusplus
extern "C"{
#endif


#ifdef __cplusplus
}
#endif

#endif /*ADVANCED_MODE_COMMAND_H*/
