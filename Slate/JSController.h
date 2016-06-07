//
//  JSController.h
//  Slate
//
//  Created by Alex Morega on 2013-01-16.
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see http://www.gnu.org/licenses

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "Operation.h"

@interface JSController : NSObject {
  WebView *webView;
  WebScriptObject *scriptObject;
  NSMutableDictionary *functions;
  BOOL inited;
  NSMutableDictionary *eventCallbacks;
}
@property NSMutableDictionary *functions;
@property NSMutableDictionary *eventCallbacks;

- (BOOL)loadConfigFileWithPath:(NSString *)path;
- (void)runCallbacks:(NSString *)what payload:(id)payload;
- (NSString *)addCallableFunction:(WebScriptObject *)function;
- (id)runCallableFunction:(NSString *)key;
- (id)runFunction:(WebScriptObject*)function;
- (id)runFunction:(WebScriptObject *)function withArg:(id)arg;
- (id)unmarshall:(id)obj;
- (id)marshall:(id)obj;
- (NSString *)jsTypeof:(WebScriptObject *)obj;
+ (JSController *)getInstance;

@end