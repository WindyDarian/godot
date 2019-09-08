// Copyright (c) 2019 Windy Darian, all rights reserved.
// Custom script library for things.

#include "register_types.h"

#include "core/class_db.h"
#include "core/engine.h"

#include "just_a_test_class.h"
#include "w.lib.h"

static _W* s_w = nullptr;

void register_windy_types()
{
	ClassDB::register_class<JustATestClass>();
	ClassDB::register_class<_W>();
	s_w = memnew(_W);
    Engine::get_singleton()->add_singleton(Engine::Singleton("W", _W::get_singleton()));
}

void unregister_windy_types()
{
	if (s_w)
	{
		memdelete(s_w);
		s_w = nullptr;
	}
}
