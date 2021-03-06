#ifndef DT3_SCRIPTINGSOUNDREVERB
#define DT3_SCRIPTINGSOUNDREVERB
//==============================================================================
///	
///	File: ScriptingSoundReverb.hpp
///	
/// Copyright (C) 2000-2014 by Smells Like Donkey Software Inc. All rights reserved.
///
/// This file is subject to the terms and conditions defined in
/// file 'LICENSE.txt', which is part of this source code package.
///	
//==============================================================================

#include "DT3Core/Scripting/ScriptingSoundBase.hpp"
#include "DT3Core/Types/Sound/SoundPacket.hpp"

//==============================================================================
//==============================================================================

namespace DT3 {

//==============================================================================
/// Forward declarations
//==============================================================================

class SoundResource;

//==============================================================================
/// Add reverb to the sound stream.
//==============================================================================

class ScriptingSoundReverb: public ScriptingSoundBase {
    public:
        DEFINE_TYPE(ScriptingSoundReverb,ScriptingSoundBase)
		DEFINE_CREATE_AND_CLONE
		DEFINE_PLUG_NODE
         
                                    ScriptingSoundReverb    (void);	
									ScriptingSoundReverb    (const ScriptingSoundReverb &rhs);
        ScriptingSoundReverb &		operator =				(const ScriptingSoundReverb &rhs);	
        virtual                     ~ScriptingSoundReverb   (void);
    
        virtual void                archive                 (const std::shared_ptr<Archive> &archive);
		
	public:
		/// Called to initialize the object
		virtual void				initialize				(void);
		
		/// Computes the value of the node
		/// \param plug plug to compute
 		DTboolean					compute					(const PlugBase *plug);

	private:		
		Plug<SoundPacket>         _sound_packet_in;
		Plug<SoundPacket>         _sound_packet_out;
        
        Plug<DTuint>                                _delay;
        Plug<DTfloat>                               _reverb_gain;
        Plug<DTfloat>                               _output_gain;
        
        std::vector<DTshort>                              _samples_left;
        std::vector<DTshort>                              _samples_right;
        DTuint                                      _sample_index;
};

//==============================================================================
//==============================================================================

} // DT3

#endif
