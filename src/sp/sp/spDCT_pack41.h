#ifndef _TORCHSPRO_SP_DCT_PACK41_H_
#define _TORCHSPRO_SP_DCT_PACK41_H_

#include "core/Tensor.h"
#include "sp/spCore.h"

namespace Torch
{
/**
 * \ingroup libsp_api
 * @{
 *
 */

  /**
   * This class is designed to perform DCT.
   * The result is a tensor of the same storage type.
   */
	class spDCT_pack41 : public spCore
	{
	public:

		/**
     *  Constructor
     */
		spDCT_pack41(bool inverse_ = false);

		/**
     *  Destructor
     */
		virtual ~spDCT_pack41();

	protected:

		//////////////////////////////////////////////////////////

		/**
     *  Check if the input tensor has the right dimensions and type - overriden
     */
		virtual bool		checkInput(const Tensor& input) const;

		/**
     *  Allocate (if needed) the output tensors given the input tensor dimensions - overriden
     */
		virtual bool		allocateOutput(const Tensor& input);

		/**
     *  Process some input tensor (the input is checked, the outputs are allocated) - overriden
     */
		virtual bool		processInput(const Tensor& input);

		//////////////////////////////////////////////////////////

	private:

		/////////////////////////////////////////////////////////////////
		// Attributes

    /**
     * Indicates if we want to compute the inverse DCT
     */
		bool inverse;


		int N;
		int H;
		int W;

		DoubleTensor *R;
	};

/**
 * @}
 */

}

#endif
