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
@property (nonatomic, strong) NSString *attribute;

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
        // In all other cases use properties.
        // It saves us from propblems with custom getters.
        _name = name;
        _data = data;
        _attribute = attribute;
    } // Use new line before return keyword.
    
    return self;
}

#pragma mark - Accessors

- (void)setName:(NSString *)name
{
    // Use direct access to instance variables only in dealloc, init and accessors.
    // In all other cases use properties.
    // It saves us from propblems with custom getters.
    if (_name != name) {
        [_name release];
        _name = [name retain];
    }
}

#pragma mark - Public Methods

- (void)load {
    [self prepareToLoading];
}

#pragma mark - Private Methods

- (void)prepareToLoading {
    // If you use property getter more than once, save it in local variable.
    // It saves us from computed properties with hard logic.
    NSString *name = self.name;
    if (name.length > kCGShortNameLength) {
        
    }
    else if (!name.length) {
        
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
