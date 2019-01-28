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
 
    1. Class methods goes.
    2. Instance methods are next.
    3. Class properties.
    4. Instance properties are in the end.
    5. Try to goup properties and methods by their logic or attributes. I.e., methods for
 initialization goes one by one and only after them goes other instance methods. 
 
 */

@protocol CGExampleDelegate <NSObject>

- (void)doSomething;

@end
// Leave one empty line after interface defclaration and first method
@interface CGExample : NSObject <CGExampleDelegate>

// If you have too many parameters to fit on one line, giving each its own line is preferred.
// If multiple lines are used, align each using the colon before the parameter.
// Length of line is 100.
// Use one space after +/-
+ (instancetype)exampleWithName:(nullable NSString *)name
                           data:(NSData *)data
                      attribute:(nullable NSString *)attribute;

// If you have too long name of method or parameter, leave it unsplitted:
// INAPPROPRIATE EXAMPLE 1
+ (instancetype)reallyLongAndComplexMoreThanMy13InchDisplayExampleWithName:(nullable NSString *)name
                                                                      data:(NSData *)data
                                                                 attribute:(nullable NSString *)attribute;

// INAPPROPRIATE EXAMPLE 2
+ (instancetype)exampleWithName:(nullable NSString *)name
reallyLongAndComplexMoreThanMy13InchDisplayData:(NSData *)data
                      attribute:(nullable NSString *)attribute;

- (instancetype)initWithName:(nullable NSString *)name
                        data:(NSData *)data
                   attribute:(nullable NSString *)attribute;

- (void)load;

// Readwrite must be omitted,
// nullable/nonnull goes first, then atomic/nonatomic, then memory attribute.
// Use one space character after @property keyword, one before and after type.
@property (nullable, nonatomic, strong) NSString *name;

// Readwrite can be omitted
@property (nonatomic, copy) NSData *data;

// Readwrite can be omitted,
// assign can be omitted as default attribute for non-object values
@property (nonatomic) BOOL local;

// Memory attribute is omitted for readonly property if you don't have corresponding readwrite
// declaration in interface extension,
// readonly goes at the end
@property (nullable, nonatomic, strong, readonly) NSString *attribute;

// There is no readwrite declaration of this property in interface extension,
// so we must omit memory attribute.
@property (nonatomic, readonly) NSObject *memoryData;

@end // Leave one empty space before @end keyword

NS_ASSUME_NONNULL_END
