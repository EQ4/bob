/**
 * @file python/ip/src/version.cc
 * @date Tue Nov 29 14:11:41 2011 +0100
 * @author Andre Anjos <andre.anjos@idiap.ch>
 *
 * @brief Describes ways to retrieve version information about all dependent
 * packages.
 *
 * Copyright (C) 2011-2012 Idiap Research Institute, Martigny, Switzerland
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <boost/python.hpp>

extern "C" {
#include <numpy/arrayobject.h>
#ifdef HAVE_VLFEAT
#include <vl/generic.h>
#endif
}

using namespace boost::python;

/**
 * VLFeat, if compiled with such support
 */
static str vlfeat_version() {
#ifdef HAVE_VLFEAT
  return str(VL_VERSION_STRING);
#else
  return str("unavailable");
#endif
}

void bind_ip_version() {
  dict vdict;
  vdict["VLfeat"] = vlfeat_version();
  scope().attr("version") = vdict;
}
