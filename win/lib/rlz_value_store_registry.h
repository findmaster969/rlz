// Copyright 2012 Google Inc. All Rights Reserved.
// Use of this source code is governed by an Apache-style license that can be
// found in the COPYING file.

#ifndef RLZ_WIN_LIB_RLZ_VALUE_STORE_REGISTRY_H_
#define RLZ_WIN_LIB_RLZ_VALUE_STORE_REGISTRY_H_

#include "base/compiler_specific.h"
#include "rlz/lib/rlz_value_store.h"

namespace rlz_lib {

extern const wchar_t kLibKeyName[];

// Implements RlzValueStore by storing values in the windows registry.
class RlzValueStoreRegistry : public RlzValueStore {
 public:
  virtual bool HasAccess(AccessType type) OVERRIDE;

  virtual bool WritePingTime(Product product, int64 time) OVERRIDE;
  virtual bool ReadPingTime(Product product, int64* time) OVERRIDE;
  virtual bool ClearPingTime(Product product) OVERRIDE;

  virtual bool WriteAccessPointRlz(AccessPoint access_point,
                                   const char* new_rlz) OVERRIDE;
  virtual bool ReadAccessPointRlz(AccessPoint access_point,
                                  char* rlz,
                                  size_t rlz_size) OVERRIDE;
  virtual bool ClearAccessPointRlz(AccessPoint access_point) OVERRIDE;

  virtual bool AddProductEvent(Product product, const char* event_rlz) OVERRIDE;
  virtual bool ReadProductEvents(Product product,
                                 std::vector<std::string>* events) OVERRIDE;
  virtual bool ClearProductEvent(Product product,
                                 const char* event_rlz) OVERRIDE;
  virtual bool ClearAllProductEvents(Product product) OVERRIDE;

  virtual bool AddStatefulEvent(Product product,
                                const char* event_rlz) OVERRIDE;
  virtual bool IsStatefulEvent(Product product,
                               const char* event_rlz) OVERRIDE;
  virtual bool ClearAllStatefulEvents(Product product) OVERRIDE;

  virtual void CollectGarbage() OVERRIDE;

 private:
  RlzValueStoreRegistry() {}
  DISALLOW_COPY_AND_ASSIGN(RlzValueStoreRegistry);
  friend class ScopedRlzValueStoreLock;
};

}  // namespace rlz_lib

#endif  // RLZ_WIN_LIB_RLZ_VALUE_STORE_REGISTRY_H_

