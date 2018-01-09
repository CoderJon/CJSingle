//
//  Single.h
//  SingleShare
//
//  Created by coderjon on 2015/5/29.
//  Copyright © 2015年 znzx@coderjon. All rights reserved.
//

#define singleH(name) + (instancetype)share##name;

#if __has_feature(objc_arc)
#define singleM(name) static id _instance;\
+ (instancetype)allocWithZone:(struct _NSZone *)zone{\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [super allocWithZone:zone];\
    });\
    return _instance;\
}\
\
+ (instancetype)share##name{\
    return [[self alloc] init];\
}\
\
- (id)copyWithZone:(NSZone *)zone{\
    return _instance;\
}\
\
- (id)mutableCopyWithZone:(NSZone *)zone{\
    return _instance;\
}

#else

#define singleM(name) static id _instance;\
+ (instancetype)allocWithZone:(struct _NSZone *)zone{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instance = [super allocWithZone:zone];\
});\
return _instance;\
}\
\
+ (instancetype)share##name{\
return [[self alloc] init];\
}\
\
- (id)copyWithZone:(NSZone *)zone{\
return _instance;\
}\
\
- (id)mutableCopyWithZone:(NSZone *)zone{\
return _instance;\
}\
\
- (oneway void)release{\
}\
\
- (instancetype)retain{\
    return _instance;\
}\
\
- (NSUInteger)retainCount{\
    return MAXFLOAT;\
}

#endif

