//
//  SmartVideo.h
//  SmartVideo
//
//  Created by Slav Sarafski on 11.05.21.
//

#import <Foundation/Foundation.h>

//! Project version number for SmartVideo.
FOUNDATION_EXPORT double SmartVideoVersionNumber;

//! Project version string for SmartVideo.
FOUNDATION_EXPORT const unsigned char SmartVideoVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SmartVideo/PublicHeader.h>

<<<<<<<< HEAD:SmartVideoSDK.xcframework/ios-arm64_x86_64-simulator/SmartVideoSDK.framework/Headers/SmartVideoSDK.h
#import <SmartVideoSDK/GCDAsyncUdpSocket.h>
#import <SmartVideoSDK/GCDAsyncSocket.h>
========

void IOSScreenSource::providePixelBuffer(long width,
                                             long height,
                                             unsigned int format,
                                             long bytesPerRow,
                                             int64_t timestamp,
                                             long rotation,
                                             long planeCount,
                                             long pdSize,
                                             const std::vector<int> planar,
                                             void *data, size_t count)
    {

        if (width == 0 || height == 0 || bytesPerRow == 0)
            return;

        RTC_LOG(LS_INFO) << "[BroadcastReceiver] provided pixelbuf timestamp: " << timestamp << " rotation: " << rotation;

        /* TO TEST PACKET RECEIVING CORRECTNESS
        if (false) {
            uint16_t* buff = (uint16_t*)data;
            
            int wordsCount = count / sizeof(uint16_t);
            for (int i = 0; i < wordsCount; ++i) {
                uint16_t v = buff[i];
                uint16_t b = ntohs(v);
                uint16_t ii = (i % 0x10000);
                assert(v == ii);
            }
            
            return;
        }
         */

        void* dataPtr = malloc(count);
        if (dataPtr == NULL) {
            return;
        }

        CVPixelBufferRef  pixelBufferOut = NULL;
        
        memcpy(dataPtr, data, count);

        // advance by dataSize, which is a plane descriptor size
        uint8_t* baseAddress = (uint8_t*) dataPtr;
        
        /* TO TRACE POINTERS ONLY
        uint32_t pd[4];
        for (int i = 0; i < 3; ++i) {
            memcpy(&pd[i], baseAddress + i*sizeof(pd[i]), sizeof(pd[i]));
        }

        printf("0: 0x%08x, 1: 0x%08x, 2: 0x%08x, 3: 0x%08x", pd[0], pd[1], pd[2], pd[3]);
        */
        baseAddress += pdSize;


        void* planeBaseAddresses[8];
        size_t planeWidths[8];
        size_t planeHeights[8];
        size_t planeBytesPerRows[8];
        uint32_t offset = 0;
        
        
        for(int i = 0, ii = 0; i < planeCount; ++i) {
            
            int planeWidth = planar[ii++];
            int planeHeight = planar[ii++];
            int planeBytesPerRow = planar[ii++];
            void *source = baseAddress + offset;
            offset += planeHeight * planeBytesPerRow;
            
            planeBaseAddresses[i] = source;
            planeWidths[i] = planeWidth;
            planeHeights[i] = planeHeight;
            planeBytesPerRows[i] = planeBytesPerRow;
        }
        
        //printf("buff: 0x%16x, plane_0: 0x%16x, plane_1: 0x%16x", dataPtr, planeBaseAddresses[0], planeBaseAddresses[1]);
        CVPixelBufferCreateWithPlanarBytes(CFAllocatorGetDefault(),
                                           width,
                                           height,
                                           (OSType) format,
                                           dataPtr,
                                           0,
                                           planeCount,
                                           planeBaseAddresses,
                                           planeWidths,
                                           planeHeights,
                                           planeBytesPerRows,
                                           pixelBufferReleasePlanarBytesCallback,
                                           NULL,
                                           NULL,
                                           &pixelBufferOut);
        
        if (pixelBufferOut != NULL) {

            /*
            CIImage *image = [CIImage imageWithCVPixelBuffer:pixelBufferOut];
            if (image != NULL) {
                RTC_LOG(LS_INFO) << "success create CIImage from pixel bufer";
            }
             */
            
            RTCCVPixelBuffer *rtcPixelBuffer = [[RTCCVPixelBuffer alloc] initWithPixelBuffer:pixelBufferOut];
            RTCVideoFrame *videoFrame = [[RTCVideoFrame alloc] initWithBuffer:rtcPixelBuffer
                                                                     rotation:rotationFromDegrees(rotation)
                                                                  timeStampNs:timestamp];
            
            [_screenCapturer.delegate capturer:_screenCapturer didCaptureVideoFrame:videoFrame];

            CVBufferRelease(pixelBufferOut);
        } else {
            RTC_LOG(LS_ERROR) << "[BroadcastReceiver] could not create pixelbuf timestamp: " << timestamp;
        }
    }
>>>>>>>> main:SmartVideoSDK.xcframework/ios-arm64_x86_64-simulator/SmartVideoSDK.framework/Headers/SmartVideo.h
