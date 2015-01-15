// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "driver/config/prelude.hpp"

#include "bson/document.hpp"
#include "stdx/optional.hpp"

namespace mongo {
namespace driver {
namespace model {

///
/// Class representing a MongoDB update operation that modifies a single document.
///
class LIBMONGOCXX_EXPORT update_one {

   public:

    ///
    /// Constructs an update operation that will modify a single document matching the filter.
    ///
    /// @param filter
    ///   Document representing the criteria for applying the update.
    /// @param update
    ///   Document representing the modifications to be applied to the matching document.
    ///
    update_one(bson::document::view filter, bson::document::view update);

    ///
    /// Gets the filter
    ///
    /// @return The filter to be used for the update operation.
    ///
    const bson::document::view& filter() const;

    ///
    /// Gets the update document.
    ///
    /// @return The modifications to be applied as part of the update.
    ///
    const bson::document::view& update() const;

    ///
    /// Sets the upsert option.
    ///
    /// By default, if no document matches the filter, the update operation does nothing.
    /// However, by specifying upsert as @c true, this operation either updates a matching document
    /// or inserts a new document using the update specification if no matching document exists.
    ///
    /// @param upsert
    ///   If set to @c true, creates a new document when no document matches the query criteria.
    ///   The server side default is @c false, which does not insert a new document if a match
    ///   is not found.
    ///
    update_one& upsert(bool upsert);

    ///
    /// Gets the current value of the upsert option.
    ///
    /// @return The optional value of the upsert option.
    ///
    const optional<bool>& upsert() const;

   private:
    // Required
    bson::document::view _filter;
    bson::document::view _update;

    // Optional
    optional<bool> _upsert;

};

}  // namespace model
}  // namespace driver
}  // namespace mongo

#include "driver/config/postlude.hpp"
