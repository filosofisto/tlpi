#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void set_time_format(const char *);
void info(const char *);
void warn(const char *);
void debug(const char *, const char *, int);
void error(const char *, const char *, int);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // MESSAGE_H_INCLUDED
