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

#import "SynergyHelper.h"

@implementation SynergyHelper

- (id) init
{    
    return self;
}

- (BOOL)isSynergyRunning
{
    return [synergy2 isRunning];
}

- (void)start:(int)kind andConnectToServer:(NSString *)serverName
{
    NSArray *args;
    NSString *binaryPath;
    NSBundle *quickSynergyBundle = [NSBundle mainBundle];
    NSString *configFile = [NSString stringWithFormat:@"%@/.QuickSynergy.config",
                            NSHomeDirectory()];
    
    switch (kind) {
        case SH_SERVER:
            binaryPath = [quickSynergyBundle pathForAuxiliaryExecutable:@"Contents/Resources/synergys"];
            synergy2 = [[NSTask alloc] init];
            [synergy2 setLaunchPath:binaryPath];
            args = [NSArray arrayWithObjects:@"-f", @"-c", configFile, nil];
            [synergy2 setArguments:args];
            [synergy2 launch];
            break;
        case SH_CLIENT:
            binaryPath = [quickSynergyBundle pathForAuxiliaryExecutable:@"Contents/Resources/synergyc"];
            synergy2 = [[NSTask alloc] init];
            [synergy2  setLaunchPath:binaryPath];
            args = [NSArray arrayWithObjects:@"-f", serverName, nil];
            [synergy2 setArguments:args];
            [synergy2 launch];
            break;
        default:
            break;
    }
}

- (void)stop
{
    [synergy2 interrupt];
    [synergy2 release];
    synergy2 = nil;
}

- (BOOL)startStop:(int)kind andConnectToServer:(NSString *)serverName
{
    
    if ([self isSynergyRunning]) {
        [self stop];
    }
    else {
        [self start:kind andConnectToServer:serverName];
    }
    
    return [self isSynergyRunning];
}

- (BOOL)startStop:(int)kind
{
    [self startStop:kind andConnectToServer:(nil)];
    
    return [self isSynergyRunning];
}

-(void)dealloc
{
    [super dealloc];
}

@end
