// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interface:srv/Drawpoly.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__STRUCT_H_
#define CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Drawpoly in the package custom_interface.
typedef struct custom_interface__srv__Drawpoly_Request
{
  int64_t a;
} custom_interface__srv__Drawpoly_Request;

// Struct for a sequence of custom_interface__srv__Drawpoly_Request.
typedef struct custom_interface__srv__Drawpoly_Request__Sequence
{
  custom_interface__srv__Drawpoly_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__Drawpoly_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Drawpoly in the package custom_interface.
typedef struct custom_interface__srv__Drawpoly_Response
{
  int64_t x;
} custom_interface__srv__Drawpoly_Response;

// Struct for a sequence of custom_interface__srv__Drawpoly_Response.
typedef struct custom_interface__srv__Drawpoly_Response__Sequence
{
  custom_interface__srv__Drawpoly_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__srv__Drawpoly_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__DRAWPOLY__STRUCT_H_
