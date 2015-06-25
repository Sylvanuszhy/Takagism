//
//  Video.h
//  Takagism
//
//  Created by 张函祎 on 15/6/25.
//  Copyright (c) 2015年 Sylvanus. All rights reserved.
//

#ifndef __Takagism__Video__
#define __Takagism__Video__

#include <stdio.h>
#include <cv.h>
#include <highgui.h>

class Video {
public:
    CvCapture *capture;
    IplImage *frame;
    void init();
    void play();
};

#endif /* defined(__Takagism__Video__) */