//
//  CGExample.m
//  CodeGuidelines
//
//  Created by Viacheslav Soroka on 1/22/19.
//  Copyright © 2019 Viacheslav Soroka. All rights reserved.
//

#import "CGExample.h"

/*
 General Rules:
 
    1. Static constants should be at the top.
    2. Interface extension should be under static constants but before implementation.
    3. Always goup your methods. Groups order should be the next:
        Class methods, dealloc, init, accessors, public methods, private methods, protocols.
 */

// For constants, use k{prefix}Name format.
// With prefix you can avoid name collision with external sources with public constants.
static const NSInteger kCGShortNameLength = 2;

@interface CGExample ()
// Use readwrite in interface extensions only to indicate, that this property is exposed to outside with
// readonly attribute. It's your responsibility to handle declaration in .h and extension consistent.
@property (nonatomic, strong, readwrite) NSString *attribute;

// Private property. No need to use readwrite attribute.
@property (nonatomic, strong) NSString *localizedData;

@end

@implementation CGExample

// Mark your group of methods with the next format: #pragma mark - {Name Of Group}.
// Use capitalized names.
#pragma mark - Class Methods

+ (instancetype)exampleWithName:(nullable NSString *)name
                           data:(NSData *)data
                      attribute:(nullable NSString *)attribute
// Transfer brace to the new line if the method can't fit in one line
{
    return [[[self alloc] initWithName:name data:data attribute:attribute] autorelease];
}

+ (instancetype)reallyLongAndComplexMoreThanMy13InchDisplayExampleWithName:(nullable NSString *)name data:(NSData *)data attribute:(nullable NSString *)attribute
// Transfer brace to the new line if the method can't fit in one line
{
    return nil;
}

+ (instancetype)exampleWithName:(nullable NSString *)name reallyLongAndComplexMoreThanMy13InchDisplayData:(NSData *)data attribute:(nullable NSString *)attribute
// Transfer brace to the new line if the method can't fit in one line
{
    return nil;
}

#pragma mark - Initializations and Deallocations

// Don't transfer brace to the new line if the method can fit in one line
- (void)dealloc {
    // Use direct access to instance variables only in dealloc, init and accessors.
    // In all other cases use properties.
    // It saves us from propblems with custom getters.
    [_name release];
    [_data release];
    [_attribute release];
    
    [super dealloc];
}

- (instancetype)initWithName:(nullable NSString *)name
                        data:(NSData *)data
                   attribute:(nullable NSString *)attribute
{
    if (self = [super init]) {
        // Use direct access to instance variables only in dealloc, init and accessors.
        // Don't use properties in init and dealloc whenever it's possible.
        // In all other cases use properties.
        // It saves us from propblems with custom getters.
        _name = name;
        _data = data;
        _attribute = attribute;
    } // Use new line before return keyword.
    
    return self;
}

#pragma mark - Accessors

- (void)setName:(NSString *)name {
    // Use direct access to instance variables only in dealloc, init and accessors.
    // In all other cases use properties.
    // It saves us from propblems with custom getters.
    if (_name != name) {
        [_name release];
        _name = [name retain];
    }
}

- (NSObject *)memoryData {
    return [NSObject new];
}

#pragma mark - Public Methods

- (void)load {
    [self prepareForLoading];
}

#pragma mark - Private Methods

- (void)prepareForLoading {
    // If you use property getter more than once, save it in local variable.
    // It saves us from computed properties with hard logic.
    // Use dot notation to access property whenever it's possible.
    NSString *name = self.name;
    if (name.length > kCGShortNameLength) { // Don't transfer brace is only one line is used
        
    } // Start each else block at new line
    else if (!name.length) {
        
    } // If you have too long expression to fit it in one line, split it in a few lines
    else if (self.data /* some very long line of code*/
             && self.attribute)
    { // If multiple lines are used, transfer brase to the new line.
        
    }
    else {
        
    } // Use empty line between closing brase and new line of code.
    
    NSLog(@"");
}

// For protocol marks, use name of protocol. It allows us to search protocol implementation by name.
#pragma mark - CGExampleDelegate

- (void)doSomething {
    
}

@end
