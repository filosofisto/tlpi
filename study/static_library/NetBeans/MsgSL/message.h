/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   message.h
 * Author: eduardo
 *
 * Created on October 29, 2016, 12:46 PM
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif

void set_time_format(char *);
void info(const char *);
void warn(const char *);
void debug(const char *, const char *, int);
void error(const char *, const char *, int);

#ifdef __cplusplus
}
#endif

#endif /* MESSAGE_H */

