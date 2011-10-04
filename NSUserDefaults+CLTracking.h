//
//  NSUserDefaults+CLTracking.h
//  NSUserDefaults+CLTracking
//
//  Created by Chris Lozac'h on 9/24/11.
//  Copyright 2011 Chris Lozac'h. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The CLTracking category gives NSUserDefaults the ability to set a
 timestamp every time a value is set with a setter of the form
 `setTrackedXXX:forKey:`. This provides two key benefits. First, it
 allows you to detect the non-existence of primitive values in
 the defaults database. Second, it allows you to easily associate
 default values with a date for cache-related purposes.
 
 * Example 1 - Non-existence *
 Say you've installed an application for the first time. The return
 value for `[[NSUserDefaults standardDefaults] boolForKey:@"someKey"];`.
 will be NO because boolForKey must return a valid BOOL.
 
 Using NSUserDefaults+Tracking, you can first call
 `isDefaultTrackedForKey:@"someKey` and then make sure to use
 `[[NSUserDefaults standardDefaults] setTrackedBool:NO forKey:@"someKey"];`
 thereafter.
 
 * Example 2
 */
@interface NSUserDefaults (CLTracking)


/** Returns true if a timestamp has been registered for defaultName. One of
 the most practical uses of this method is to avoid the "false value" issue
 caused when NSUserDefaults returns a default value for primitive types.
 For example, asking NSUserDefaults for an integer default will return
 0 if the defaults database contains an entry for your key with a value of
 zero, but it will also return 0 if the defaults database contains no entry
 at all for your key.
 
 By using tracked defaults, you can first call isDefaultTrackedForKey to
 determine whether the key has ever been registered as a tracked default.
 If it has, then you can be confident, when you subsequently ask
 for the value, that the value you get back is not a default.
 */
- (BOOL)isDefaultTrackedForKey:(NSString *)defaultName;

/** Returns a timestamp generated at the time that a value was last set for
 the key.
 */
- (NSDate *)timestampForKey:(NSString *)defaultName;

/** 
 Sets the value of the specified default key to the specified Boolean value,
 along with a timestamp tied to the same key. Invokes setBool:forKey: as
 part of its implementation.
 
 @return A timestamp indicating the time the value was last set as a default.
 @param value The Boolean value to store in the defaults database.
 @param defaultName The key with which to associate with the value.
 */
- (void)setTrackedBool:(BOOL)value forKey:(NSString *)defaultName;

/**
 Sets the value of the specified default key to the specified floating-point value,
 along with a timestamp tied to the same key. Invokes setFloat:forKey: as
 part of its implementation.

 @return A timestamp indicating the time the value was last set as a default.
 @param The floating-point value to store in the defaults database.
 @param The key with which to associate with the value.
 */
- (void)setTrackedFloat:(float)value forKey:(NSString *)defaultName;

/**
 Sets the value of the specified default key to the specified integer value,
 along with a timestamp tied to the same key. Invokes setInteger:forKey: as
 part of its implementation.

 @return A timestamp indicating the time the value was last set as a default.
 @param The integer value to store in the defaults database.
 @param The key with which to associate with the value.
 */
- (void)setTrackedInteger:(NSInteger)value forKey:(NSString *)defaultName;

/**
 Sets the value of the specified default key in the standard application domain,
 along with a timestamp tied to the same key. Invokes setObject:forKey: as
 part of its implementation.

 @return A timestamp indicating the time the value was last set as a default.
 @param The object to store in the defaults database.
 @param The key with which to associate with the value.
 */
- (void)setTrackedObject:(id)value forKey:(NSString *)defaultName;

/**
 Sets the value of the specified default key to the double value,
 along with a timestamp tied to the same key. Invokes setDouble:forKey: as
 part of its implementation.

 @return A timestamp indicating the time the value was last set as a default.
 @param The double value.
 @param The key with which to associate with the value. 
 */
- (void)setTrackedDouble:(double)value forKey:(NSString *)defaultName;

/**
 Sets the value of the specified default key to the specified URL,
 along with a timestamp tied to the same key. Invokes setURL:forKey: as
 part of its implementation.

 @return A timestamp indicating the time the value was last set as a default.
 @param The NSURL to store in the defaults database.
 @param The key with which to associate with the value. 
 */
- (void)setTrackedURL:(NSURL *)url forKey:(NSString *)defaultName;

/**
 Removes the value of the specified default key in the standard application domain,
 and removes the corresponding timestamp. Invokes removeObjectForKey: as
 part of its implementation.
 
 @param The key whose value and timestamp you want to remove.
 */
- (void)removeTrackedObjectForKey:(NSString *)defaultValue;

/**
 Removes the timestamp for defaultName. Any stored value for the key will
 remain in the defaults database.
 
 Use this method if you no longer have use for the tracking timestamp
 for a given default, or if you need to reset a default's tracking.

 @param The key whose timestamp you want to remove.
 
 @see removeTrackedObjectForKey:
 */
- (void)removeTrackingForKey:(NSString *)defaultName;

@end
