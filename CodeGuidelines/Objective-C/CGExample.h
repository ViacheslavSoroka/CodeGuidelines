//
//  CGExample.h
//  CodeGuidelines
//
//  Created by Viacheslav Soroka on 1/22/19.
//  Copyright © 2019 Viacheslav Soroka. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
 General Rules:
 
    1. Properties goes first.
    2. Class methods are next.
    3. Instance methods are in the end.
 */

@protocol CGExampleDelegate <NSObject>

- (void)doSomething;

@end

@interface CGExample : NSObject <CGExampleDelegate>
// readwrite can be omitted,
// nullable/nonnull goes first, then atomic/nonatomic, then memory attribute.
// Use one empty line after @property keyword, one before and after type.
@property (nullable, nonatomic, strong) NSString *name;

// readwrite can be omitted
@property (nonatomic, copy) NSData *data;

// readwrite can be omitted,
// assign is desired for readability (each property has 2 attributes, except of nullable attribute)
@property (nonatomic, assign) BOOL local;

// memory attribute is omitted for readonly property,
// readonly goes at the end
@property (nullable, nonatomic, readonly) NSString *attribute;

// If you have too many parameters to fit on one line, giving each its own line is preferred.
// If multiple lines are used, align each using the colon before the parameter.
// Length of line is 100.
// Use one space after +/- 
+ (instancetype)exampleWithName:(nullable NSString *)name
                           data:(NSData *)data
                      attribute:(nullable NSString *)attribute;

- (instancetype)initWithName:(nullable NSString *)name
                        data:(NSData *)data
                   attribute:(nullable NSString *)attribute;

- (void)load;

@end

NS_ASSUME_NONNULL_END
