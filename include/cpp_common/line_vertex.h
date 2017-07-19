/*PGR-GNU*****************************************************************
File: line_vertex.h
Generated with Template by:
Copyright (c) 2015 pgRouting developers
Mail: project@pgrouting.org

Function's developer:
Copyright (c) 2017 Vidhan Jain
Mail: vidhanj1307@gmail.com

------

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

********************************************************************PGR-GNU*/

/*! @file */

#ifndef INCLUDE_CPP_COMMON_LINE_VERTEX_H_
#define INCLUDE_CPP_COMMON_LINE_VERTEX_H_
#pragma once

#include <vector>
#include <ostream>

#include "c_types/pgr_edge_t.h"



namespace pgrouting {

class Line_vertex {
 public:
     Line_vertex() :
         id(0) {}

     Line_vertex(int64_t _id, int64_t _source, int64_t _target, double _cost) :
         id(_id),
         source(_source),
         target(_target),
         cost(_cost) {}

     Line_vertex(const pgr_edge_t& edge) :
         id(edge.id),
         source(edge.source),
         target(edge.target),
         cost(edge.cost) {}

     Line_vertex(const Line_vertex &v) :
         id(v.id),
         source(v.source),
         target(v.target),
         cost(v.cost) {}

     void cp_members(const Line_vertex &other) {
         this->id = other.id;
         this->cost = other.cost;
         this->source = other.source;
         this->target = other.target;
     }


     friend std::ostream& operator<<(std::ostream& log, const Line_vertex &v);
 public:
     int64_t id;
     int64_t source;
     int64_t target;
     double cost;
};

size_t check_vertices(std::vector < Line_vertex > vertices);

std::vector < Line_vertex > extract_vertices(
        std::vector < Line_vertex > vertices,
        const pgr_edge_t *data_edges, int64_t count);

std::vector < Line_vertex > extract_vertices(
        std::vector < Line_vertex > vertices,
        const std::vector < pgr_edge_t > data_edges);

std::vector < Basic_vertex > extract_vertices_from_edges(
        const pgr_edge_t *data_edges, int64_t count);

std::vector < Basic_vertex > extract_vertices_from_edges(
        const std::vector < pgr_edge_t > data_edges);

}  // namespace pgrouting

#endif  // INCLUDE_CPP_COMMON_LINE_VERTEX_H_
