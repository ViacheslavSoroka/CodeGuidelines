//
//  CGExample.h
//  CodeGuidelines
//
//  Created by Viacheslav Soroka on 1/22/19.
//  Copyright © 2019 Viacheslav Soroka. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Names of enum's values should begin with the enum's name.
// This approach simplifies choosing appropriate value
// via autocompletion.
typedef NS_ENUM(uint8_t, PROrderLayoutType) {
    PROrderLayoutTypePhone = 0,
    PROrderLayoutTypePhoneWithOtherIssues,
    PROrderLayoutTypePadSingleColumn,
    PROrderLayoutTypePadMultiColumn
};

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

// 1. If you have too many parameters to fit on one line, giving each its own line is preferred.
// 2. If multiple lines are used, align each using the colon before the parameter.
// 3. Length of line is ~100.
// 4. One space after method's type sign (+/-).
// 5. No space between return type's bracket and method's name.
// 6. Methods/parameters names start with a small letter unless they’re abbreviations (like CID, UUID, etc.).
// 5. Pointer sign (*) is detached from type.
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
- (void)requestIssueDatesForCID:(NSString *)CID;

// 1. Readwrite must be omitted.
// 2. nullable/nonnull goes first, then atomic/nonatomic, then memory attribute.
// 3. Use one space character after @property keyword, one before and after type.
// 4. Property name start with a small letter unless it's an abbreviation (like CID, UUID, etc.).
// 5. Pointer sign (*) is attached to the name.
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
