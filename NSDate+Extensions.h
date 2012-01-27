#import <Foundation/Foundation.h>

#define D_MINUTE	60
#define D_HOUR		3600
#define D_DAY		86400
#define D_WEEK		604800
#define D_YEAR		31556926

@interface NSDate (Utilities)

// Relative dates from the current date
+ (NSDate *) dateTomorrow;
+ (NSDate *) dateYesterday;
+ (NSDate *) dateWithDaysFromNow: (NSUInteger) days;
+ (NSDate *) dateWithDaysBeforeNow: (NSUInteger) days;
+ (NSDate *) dateWithHoursFromNow: (NSUInteger) dHours;
+ (NSDate *) dateWithHoursBeforeNow: (NSUInteger) dHours;
+ (NSDate *) dateWithMinutesFromNow: (NSUInteger) dMinutes;
+ (NSDate *) dateWithMinutesBeforeNow: (NSUInteger) dMinutes;

// Comparing dates
- (BOOL) isEqualToDateIgnoringTime: (NSDate *) aDate;
- (BOOL) isToday;
- (BOOL) isTomorrow;
- (BOOL) isYesterday;
- (BOOL) isSameWeekAsDate: (NSDate *) aDate;
- (BOOL) isThisWeek;
- (BOOL) isNextWeek;
- (BOOL) isLastWeek;
- (BOOL) isSameYearAsDate: (NSDate *) aDate;
- (BOOL) isThisYear;
- (BOOL) isNextYear;
- (BOOL) isLastYear;
- (BOOL) isEarlierThanDate: (NSDate *) aDate;
- (BOOL) isLaterThanDate: (NSDate *) aDate;

// Adjusting dates
- (NSDate *) dateByAddingDays: (NSUInteger) dDays;
- (NSDate *) dateBySubtractingDays: (NSUInteger) dDays;
- (NSDate *) dateByAddingHours: (NSUInteger) dHours;
- (NSDate *) dateBySubtractingHours: (NSUInteger) dHours;
- (NSDate *) dateByAddingMinutes: (NSUInteger) dMinutes;
- (NSDate *) dateBySubtractingMinutes: (NSUInteger) dMinutes;
- (NSDate *) dateAtStartOfDay;

// Retrieving intervals
- (NSInteger) minutesAfterDate: (NSDate *) aDate;
- (NSInteger) minutesBeforeDate: (NSDate *) aDate;
- (NSInteger) hoursAfterDate: (NSDate *) aDate;
- (NSInteger) hoursBeforeDate: (NSDate *) aDate;
- (NSInteger) daysAfterDate: (NSDate *) aDate;
- (NSInteger) daysBeforeDate: (NSDate *) aDate;


// Returns an NSDate based on a string with formatting options passed to NSDateFormatter
+ (NSDate*)dateWithString:(NSString*)dateString formatString:(NSString*)dateFormatterString;

// Returns an NSDate with an ISO8610 format, aka ATOM: yyyy-MM-dd'T'HH:mm:ssZZZ 
+ (NSDate*)dateWithISO8601String:(NSString*)str;

// Returns an NSDate with a 'yyyy-MM-dd' string
+ (NSDate*)dateWithDateString:(NSString*)str;

// Returns an NSDate with a 'yyyy-MM-dd HH:mm:ss' string
+ (NSDate*)dateWithDateTimeString:(NSString*)str;

// Returns an NSDate with a 'dd MMM yyyy HH:mm:ss' string
+ (NSDate*)dateWithLongDateTimeString:(NSString*)str;

// Returns an NSDate with an RSS formatted string: 'EEE, d MMM yyyy HH:mm:ss ZZZ' string
+ (NSDate*)dateWithRSSDateString:(NSString*)str;

// Returns an NSDate with an alternative RSS formatted string: 'd MMM yyyy HH:mm:ss ZZZ' string
+ (NSDate*)dateWithAltRSSDateString:(NSString*)str;

// just now, 2 minutes ago, 2 hours ago, 2 days ago, etc.
- (NSString*)formattedExactRelativeDate;

// Pass in an string compatible with NSDateFormatter
- (NSString*)formattedDateWithFormatString:(NSString*)dateFormatterString;

// Returns date formatted to: EEE, d MMM 'at' h:mma
- (NSString*)formattedDate;

// Returns date formatted to: NSDateFormatterShortStyle
- (NSString*)formattedTime;

// Returns date formatted to: Weekday if within last 7 days, Yesterday/Tomorrow, or NSDateFormatterShortStyle for everything else
- (NSString*)relativeFormattedDate;

// Returns date formatted to: Weekday if within last 7 days, Yesterday/Today/Tomorrow, or NSDateFormatterShortStyle for everything else
// If date is today, returns no Date, instead returns NSDateFormatterShortStyle for time
- (NSString*)relativeFormattedDateOnly;

// Returns date formatted to: Weekday if within last 7 days, Yesterday/Today/Tomorrow, or NSDateFormatterFullStyle for everything else
// Also returns NSDateFormatterShortStyle for time
- (NSString*)relativeFormattedDateTime;

// Returns date formatted to: Weekday if within last 7 days, Yesterday/Today/Tomorrow, or NSDateFormatterFullStyle for everything else
- (NSString*)relativeLongFormattedDate;

// Returns date formatted for ISO8601/ATOM: yyyy-MM-dd'T'HH:mm:ssZZZ
- (NSString*)iso8601Formatted;

// yyyy-MM-dd based on local timezone
- (NSString*)dateString;

// Checks whether current date is past date
- (BOOL)isPastDate;

// Checks whether the current date occured today
- (BOOL)isDateToday;

// Checks whether the current date occured yesterday
- (BOOL)isDateYesterday;

// Returns the current date, at midnight
- (NSDate*)midnightDate;

// Get days number of the month
- (NSInteger) monthDays;

// Decomposing dates
@property (readonly) NSInteger nearestHour;
@property (readonly) NSInteger hour;
@property (readonly) NSInteger minute;
@property (readonly) NSInteger seconds;
@property (readonly) NSInteger day;
@property (readonly) NSInteger month;
@property (readonly) NSInteger week;
@property (readonly) NSInteger weekday;
@property (readonly) NSInteger nthWeekday; // e.g. 2nd Tuesday of the month == 2
@property (readonly) NSInteger year;
@end