// ======================================================================
//
// Copyright (c) 1999 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
// 
// release       : $CGAL_Revision: CGAL-2.1-I-28 $
// release_date  : $CGAL_Date: 1999/10/12 $
// 
// source        : user_classes.fw
// file          : include/CGAL/user_classes.h
// package       : Kernel_basic (2.7.2)
// revision      : 2.7.2
// revision_date : 11 Oct 1999 
// author(s)     : Andreas Fabri
//                 Stefan Schirra
//
// coordinator   : MPI, Saarbruecken  (<Stefan.Schirra@mpi-sb.mpg.de>)
// ======================================================================
 

#ifndef CGAL_USER_CLASSES_H
#define CGAL_USER_CLASSES_H

CGAL_BEGIN_NAMESPACE

template < class R >
class Point_2;

template < class R >
class Vector_2;

template < class R >
class Direction_2;

template < class R >
class Line_2;

template < class R >
class Ray_2;

template < class R >
class Segment_2;

template < class R >
class Triangle_2;

template < class R >
class Iso_rectangle_2;

template < class R >
class Iso_rectangle_3;

template < class R >
class Circle_2;

template < class R >
class Aff_transformation_base_2;

template < class R >
class Aff_transformation_2;

template < class R >
class Aff_transformation_3;

template < class R >
class Plane_3;

template < class FT >
class Point_3;

template < class FT >
class Vector_3;

template < class FT >
class Direction_3;

template < class R >
class Line_3;

template < class FT >
class Ray_3;

template < class FT >
class Segment_3;

template < class FT >
class Triangle_3;

template < class FT >
class Tetrahedron_3;


// template < class R >
// class _Vector_2_rft_wrapper;
// 
// template < class R >
// class _Vector_3_rft_wrapper;

template < class R>
class Point_d;

template < class R>
class Vector_d;

template < class R>
class Direction_d;

CGAL_END_NAMESPACE

#endif  // CGAL_USER_CLASSES_H
