//
//  NSUserDefaults+CLTracking.m
//  NSUserDefaults+CLTracking
//
//  Created by Chris Lozac'h on 9/24/11.
//  Copyright 2011 Chris Lozac'h. All rights reserved.
//

#import "NSUserDefaults+Tracking.h"

static NSString *kTimeStampKeyPrefix = @"clTstmp_";

@implementation NSUserDefaults (CLTracking)

#pragma mark - Private

- (NSString *)timestampKeyForKey:(NSString *)defaultName {
    
    NSString *newKey = [NSString stringWithFormat:@"%@%@", kTimeStampKeyPrefix, defaultName];
    return newKey;
}

- (void)setTimestampForKey:(NSString *)defaultName {
    
    NSString *timestampKey = [self timestampKeyForKey:defaultName];
    [self setObject:[NSDate date] forKey:timestampKey];
}

#pragma mark - Public

- (NSDate *)timestampForKey:(NSString *)defaultName {
    
    NSString *timestampKey = [self timestampKeyForKey:defaultName];
    NSDate *timestamp = [self objectForKey:timestampKey];
    return timestamp;
}

- (BOOL)isDefaultTrackedForKey:(NSString *)defaultName {
    
    NSDate *timestamp = [self timestampForKey:defaultName];
    return timestamp != nil;
}

- (void)setTrackedBool:(BOOL)value forKey:(NSString *)defaultName {
    
    [self setTimestampForKey:defaultName];
    [self setBool:value forKey:defaultName];
}

- (void)setTrackedFloat:(float)value forKey:(NSString *)defaultName {
    
    [self setTimestampForKey:defaultName];
    [self setFloat:value forKey:defaultName];
}

- (void)setTrackedInteger:(NSInteger)value forKey:(NSString *)defaultName {

    [self setTimestampForKey:defaultName];
    [self setInteger:value forKey:defaultName];
}

- (void)setTrackedObject:(id)value forKey:(NSString *)defaultName {
    
    [self setTimestampForKey:defaultName];
    [self setObject:value forKey:defaultName];
}

- (void)setTrackedDouble:(double)value forKey:(NSString *)defaultName {
    
    [self setTimestampForKey:defaultName];
    [self setDouble:value forKey:defaultName];
}

- (void)setTrackedURL:(NSURL *)url forKey:(NSString *)defaultName {
 
    [self setTimestampForKey:defaultName];
    [self setURL:url forKey:defaultName];
}

- (void)removeTrackingForKey:(NSString *)defaultName {
    
    NSString *timestampKey = [self timestampKeyForKey:defaultName];
    [self removeObjectForKey:timestampKey];
}

- (void)removeTrackedObjectForKey:(NSString *)defaultValue {
    
    [self removeObjectForKey:defaultValue];
    [self removeTrackingForKey:defaultValue];
}
     
@end
