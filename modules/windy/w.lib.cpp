// Copyright (c) 2019 Windy Darian, all rights reserved.
// Custom script library for things.

#include "w.lib.h"

static Dictionary* _get_tag_dictionary()
{
	// FIXME: multithreading
	static Dictionary tag_name_to_tag_id;
	return &tag_name_to_tag_id;
}

_W* _W::singleton = nullptr;

// static void _register_tag_recursive(const String& tag_name, int depth)
// {
// 	if (depth >= 4)
// 	{
// 		print_error(String("Tag name has more than 4 segments. Currently only support 4. - ") + tag_name);
// 		return;
// 	}
// }

static void _register_tag(const String& tag_name)
{
	Dictionary& tag_dictionary = *_get_tag_dictionary();
	int split_location = -1;
	do {
		split_location = tag_name.find_char('.', split_location + 1);
		String current_parent_tag_name = tag_name.substr(0, split_location);
		Variant current_parent_tag_name_variant = {current_parent_tag_name};
		if (!tag_dictionary.has(current_parent_tag_name_variant))
		{
			tag_dictionary[current_parent_tag_name_variant] = 0; // TODO
		}
	} while (split_location >= 0);
	// TODO: finish register_tag and expose to gdscript!
}

static void _spatial_set_rotation_quat(Spatial *spatial, const Quat &rotation)
{
	ERR_FAIL_NULL(spatial);
	Transform transform = spatial->get_transform();
	transform.set_basis(Basis(rotation));
	spatial->set_transform(transform);
}
void _W::spatial_set_rotation_quat(Node *spatial, const Quat &rotation) const   // Note: Spatial doesn't have conversion to Variant...
{
	_spatial_set_rotation_quat(Object::cast_to<Spatial>(spatial), rotation);
}

static void _spatial_set_rotation_quat_keep_scale(Spatial *spatial, const Quat &rotation)
{
	ERR_FAIL_NULL(spatial);
	Transform transform = spatial->get_transform();
	Vector3 original_scale(transform.basis.get_scale());
	transform.set_basis(Basis(rotation, original_scale));
	spatial->set_transform(transform);
}
void _W::spatial_set_rotation_quat_keep_scale(Node* spatial, const Quat& rotation) const
{
	_spatial_set_rotation_quat_keep_scale(Object::cast_to<Spatial>(spatial), rotation);
}

static Quat _spatial_get_rotation_quat(const Spatial *spatial)
{
	ERR_FAIL_NULL_V(spatial, Quat());
	return spatial->get_transform().basis.get_rotation_quat();
}
Quat _W::spatial_get_rotation_quat(const Node *spatial) const
{
	return _spatial_get_rotation_quat(Object::cast_to<Spatial>(spatial));
}

void _W::_bind_methods() {
	ClassDB::bind_method(D_METHOD("spatial_set_rotation_quat", "spatial", "quat"), &_W::spatial_set_rotation_quat);
	ClassDB::bind_method(D_METHOD("spatial_set_rotation_quat_keep_scale", "spatial", "quat"), &_W::spatial_set_rotation_quat_keep_scale);
	ClassDB::bind_method(D_METHOD("spatial_get_rotation_quat", "spatial"), &_W::spatial_get_rotation_quat);
}

_W::_W()
{
	_W::singleton = this;
}
