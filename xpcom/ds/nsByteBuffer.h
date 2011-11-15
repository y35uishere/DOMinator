/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
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
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
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

#ifndef nsByteBuffer_h__
#define nsByteBuffer_h__

#include "nsIByteBuffer.h"

class ByteBufferImpl : public nsIByteBuffer {
public:
  ByteBufferImpl(void);

  NS_DECL_ISUPPORTS

  static nsresult
  Create(nsISupports *aOuter, REFNSIID aIID, void **aResult);

  NS_IMETHOD Init(PRUint32 aBufferSize);
  NS_IMETHOD_(PRUint32) GetLength(void) const;
  NS_IMETHOD_(PRUint32) GetBufferSize(void) const;
  NS_IMETHOD_(char*) GetBuffer() const;
  NS_IMETHOD_(PRBool) Grow(PRUint32 aNewSize);
  NS_IMETHOD_(PRInt32) Fill(nsresult* aErrorCode, nsIInputStream* aStream,
                            PRUint32 aKeep);

  char* mBuffer;
  PRUint32 mSpace;
  PRUint32 mLength;
private:
  ~ByteBufferImpl();
};

#endif // nsByteBuffer_h__