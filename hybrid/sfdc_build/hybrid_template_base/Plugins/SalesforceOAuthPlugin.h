/*
 Copyright (c) 2011, salesforce.com, inc. All rights reserved.
 
 Redistribution and use of this software in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions
 and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of
 conditions and the following disclaimer in the documentation and/or other materials provided
 with the distribution.
 * Neither the name of salesforce.com, inc. nor the names of its contributors may be used to
 endorse or promote products derived from this software without specific prior written
 permission of salesforce.com, inc.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <PhoneGap/PGPlugin.h>
#import "SFOAuthCoordinator.h"

@class SFAuthorizingViewController;
@class AppDelegate;

@interface SalesforceOAuthPlugin : PGPlugin <SFOAuthCoordinatorDelegate, UIAlertViewDelegate> {
    SFOAuthCoordinator *_coordinator;
    AppDelegate *_appDelegate;
    NSString *_callbackId;
    BOOL _isAuthenticating;
    NSString *_remoteAccessConsumerKey;
    NSString *_oauthRedirectURI;
    NSString *_oauthLoginDomain;
    NSString *_userAccountIdentifier;
    NSSet *_oauthScopes;
}

/**
 The SFOAuthCoordinator used for managing login/logout.
 */
@property (nonatomic, readonly) SFOAuthCoordinator *coordinator;

/**
 The Remote Access object consumer key.
 */
@property (nonatomic, copy) NSString *remoteAccessConsumerKey;

/**
 The Remote Access object redirect URI
 */
@property (nonatomic, copy) NSString *oauthRedirectURI;

/**
 The Remote Access object Login Domain
 */
@property (nonatomic, copy) NSString *oauthLoginDomain;

/**
 The set of oauth scopes that should be requested for this app.
 */
@property (nonatomic, retain) NSSet *oauthScopes;

/**
 An account identifier such as most recently used username.
 */
@property (nonatomic, copy) NSString *userAccountIdentifier;

/**
 Forces a logout from the current account.
 This throws out the OAuth refresh token.
 */
- (void)logout;

/**
 Kick off the login process.
 */
- (void)login;

/**
 Sent whenever the user has been logged in using current settings.
 Be sure to call super if you override this.
 */
- (void)loggedIn;

/**
 PhoneGap plug-in method to get the currently configured login host from the app's
 settings.
 */
- (void)getLoginHost:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

//TODO rename this something that makes more sense, header doc
- (void)getAccessInfo:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

/**
 PhoneGap plug-in method to authenticate a user to the application.
 */
- (void)authenticate:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

/**
 Used to reset the application to its initial state, with a cleared authentication state.
 */
- (BOOL)resetAppState;

@end
