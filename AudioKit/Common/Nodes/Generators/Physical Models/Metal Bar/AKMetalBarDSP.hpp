// Copyright AudioKit. All Rights Reserved. Revision History at http://github.com/AudioKit/AudioKit/

#pragma once

#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(AUParameterAddress, AKMetalBarParameter) {
    AKMetalBarParameterLeftBoundaryCondition,
    AKMetalBarParameterRightBoundaryCondition,
    AKMetalBarParameterDecayDuration,
    AKMetalBarParameterScanSpeed,
    AKMetalBarParameterPosition,
    AKMetalBarParameterStrikeVelocity,
    AKMetalBarParameterStrikeWidth,
};

#ifndef __cplusplus

AKDSPRef createMetalBarDSP(void);

#else

#import "AKSoundpipeDSPBase.hpp"

class AKMetalBarDSP : public AKSoundpipeDSPBase {
private:
    struct InternalData;
    std::unique_ptr<InternalData> data;
 
public:
    AKMetalBarDSP();

    void init(int channelCount, double sampleRate) override;

    void deinit() override;

    void reset() override;

    void process(AUAudioFrameCount frameCount, AUAudioFrameCount bufferOffset) override;
};

#endif
