/*
 * QuickSynergy: Synergy in a single click
 * Copyright (C) 2005-2009 Otávio Cordeiro. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#import <Cocoa/Cocoa.h>

#define SH_SERVER 0x0001
#define SH_CLIENT 0x0002

@interface SynergyHelper : NSObject
{
    NSTask *synergy2;
}

- (BOOL)isSynergyRunning;
- (BOOL)startStop:(int)kind;
- (BOOL)startStop:(int)kind andConnectToServer:(NSString *)serverName;

@end
