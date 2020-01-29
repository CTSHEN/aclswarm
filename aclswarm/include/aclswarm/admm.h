/**
 * @file admm.h
 * @brief Wrapper for ADMM-based gain design generated by MATLAB
 * @author Parker Lusk <parkerclusk@gmail.com>
 * @date 29 Jan 2020
 */

#pragma once

#include <iostream>
#include <iomanip>

#include <Eigen/Dense>

/// \brief MATLAB generated files. From lib/codegen_admm.
#include <ADMMGainDesign3D.h>
#include <ADMMGainDesign3D_terminate.h>
#include <ADMMGainDesign3D_emxutil.h>
#include <ADMMGainDesign3D_emxAPI.h>
#include <ADMMGainDesign3D_initialize.h>

#include "aclswarm/utils.h"

namespace acl {
namespace aclswarm {

  class ADMM
  {
  public:
    ADMM(const size_t n);
    ~ADMM();
    
    GainMat calculateFormationGains(const PtsMat& p, const AdjMat& adjmat);

  private:
    /// \brief MATLAB 2D emxArray container
    emxArray_real_T * Aopt_; ///< resulting 3nx3n gain matrix

    void emxPrint(emxArray_real_T * emx);
  };

} // ns aclswarm
} // ns acl
