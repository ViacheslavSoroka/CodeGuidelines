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
 
    ?>  1. CLASS METHODS
        2. INSTANCE METHODS
        3. CLASS PROPERTIES (*)
        4. PROPERTIES
 
    >   Class methods have superior position over instance's methods/properties and
        it makes sense to declare them first.
        But then it becomes not handy to split class and instance's methods by properties
        declaration, as often inits and static 'factory' methods have the same semantics
        and must be edited together.
 
        (*) Logically it's more appropriate to place them at #2, but it leads to splitting
            +/- methods. Anyway having class properties is rather an exception.
 */

@protocol CGExampleDelegate <NSObject>

- (void)doSomething;

@end

@interface CGExample : NSObject <CGExampleDelegate>
// readwrite can be omitted,
// nullable/nonnull goes first, then atomic/nonatomic, then memory attribute.
// Use one space character after @property keyword, one before and after type.
@property (nullable, nonatomic, strong) NSString *name;

// readwrite can be omitted
@property (nonatomic, copy) NSData *data;

// readwrite can be omitted,
// assign is desired for readability (each property has 2 attributes, except of nullable attribute)
// ?> ASSIGN MAY BE OMITTED AS IT'S WHAT WE HAVE BY DEFAULT THERE. HAVING OR NOT HAVING IT
// DOESN'T AFFECT READABILITY.
@property (nonatomic, assign) BOOL local;

// memory attribute is omitted for readonly property,
// readonly goes at the end
// ?> AS WE DISCUSSED IT MAKES SENSE TO HAVE MEMORY SPECIFIER IF PROPERTY IS ACTULALLY
// READWRITABLE PRIVATELY. THIS INFORMATION IS NECESSARY FOR DEV.PURPOSES DURING
// MAKING DECISION ABOUT HOW TO OVERRIDE PROPERTY WITHOUT NEED OF DIGGING THE CODE.
// BESIDES HAVING @property (nonatomic,strong, readwrite) NSString *attribute IN .m
// FILE INDICATES THAT PROPERTY IS ACTUALLY DISPOSED TO OUTSIDE.
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

// ?> KEY WORD IN THIS RULE MUST BE 'PREFERRED' AS THERE ARE SITUATIONS
// WHEN IT'S BETTER TO LEAVE LONG METHOD UNSPLITTED.

// INAPPROPRIATE EXAMPLE 1
+ (instancetype)reallyLongAndComplexMoreThanMy13InchDisplayExampleWithName:(nullable NSString *)name
                                                                      data:(NSData *)data
                                                                 attribute:(nullable NSString *)attribute;

// INAPPROPRIATE EXAMPLE 2
+ (instancetype)exampleWithName:(nullable NSString *)name
reallyLongAndComplexMoreThanMy13InchDisplayData:(NSData *)data
                      attribute:(nullable NSString *)attribute;


- (void)load;

@end

NS_ASSUME_NONNULL_END
