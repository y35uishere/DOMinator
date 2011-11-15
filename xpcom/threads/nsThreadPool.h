/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 sts=2 et cindent: */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla code.
 *
 * The Initial Developer of the Original Code is Google Inc.
 * Portions created by the Initial Developer are Copyright (C) 2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *  Darin Fisher <darin@meer.net>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef nsThreadPool_h__
#define nsThreadPool_h__

#include "nsIThreadPool.h"
#include "nsIThread.h"
#include "nsIRunnable.h"
#include "nsEventQueue.h"
#include "nsCOMArray.h"
#include "nsCOMPtr.h"

class nsThreadPool : public nsIThreadPool, public nsIRunnable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEVENTTARGET
  NS_DECL_NSITHREADPOOL
  NS_DECL_NSIRUNNABLE

  nsThreadPool();

private:
  ~nsThreadPool();

  void ShutdownThread(nsIThread *thread);
  nsresult PutEvent(nsIRunnable *event);

  nsCOMArray<nsIThread> mThreads;
  nsEventQueue          mEvents;
  PRUint32              mThreadLimit;
  PRUint32              mIdleThreadLimit;
  PRUint32              mIdleThreadTimeout;
  PRUint32              mIdleCount;
  nsCOMPtr<nsIThreadPoolListener> mListener;
  PRBool                mShutdown;
};

#define NS_THREADPOOL_CLASSNAME "nsThreadPool"
#define NS_THREADPOOL_CID                          \
{ /* 547ec2a8-315e-4ec4-888e-6e4264fe90eb */       \
  0x547ec2a8,                                      \
  0x315e,                                          \
  0x4ec4,                                          \
  {0x88, 0x8e, 0x6e, 0x42, 0x64, 0xfe, 0x90, 0xeb} \
}

#endif  // nsThreadPool_h__