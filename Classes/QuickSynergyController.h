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
#import <Growl/Growl.h>
#import "SynergyHelper.h"

#define GROWL_QS_STARTED @"Started"
#define GROWL_QS_STOPPED @"Stopped"
#define GROWL_QS_ERROR   @"Error"

#define TAB_SHARE @"Share"
#define TAB_USE   @"Use"

@interface QuickSynergyController : NSObject <GrowlApplicationBridgeDelegate>
{
    SynergyHelper *synergy;
	BOOL isItRunning;
    
    IBOutlet NSTextField *clientAbove;
    IBOutlet NSTextField *clientBelow;
    IBOutlet NSTextField *clientLeft;
    IBOutlet NSTextField *clientRight;
    IBOutlet NSTextField *serverAddr;
    IBOutlet NSButton *startStopButton;
    IBOutlet NSTabView *tabview;
    IBOutlet NSMenuItem *startStopMenuItem;
}

- (IBAction)startStop:(id)sender;
- (IBAction)gotoTab:(id)sender;
- (IBAction)gotoPage:(id)sender;

- (void) fileNotifications;
@end
