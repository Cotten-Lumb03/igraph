/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2009  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#ifndef IGRAPH_GAMES_H
#define IGRAPH_GAMES_H

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

#include "igraph_constants.h"
#include "igraph_types.h"
#include "igraph_datatype.h"

__BEGIN_DECLS

/* -------------------------------------------------- */
/* Constructors, games (=stochastic)                  */
/* -------------------------------------------------- */

int igraph_barabasi_game(igraph_t *graph, igraph_integer_t n, igraph_integer_t m, 
			 const igraph_vector_t *outseq, igraph_bool_t outpref, 
			 igraph_bool_t directed);
int igraph_nonlinear_barabasi_game(igraph_t *graph, igraph_integer_t n,
				   igraph_real_t power,
				   igraph_integer_t m,  
				   const igraph_vector_t *outseq,
				   igraph_bool_t outpref,
				   igraph_real_t zeroappeal,
				   igraph_bool_t directed);
int igraph_erdos_renyi_game(igraph_t *graph, igraph_erdos_renyi_t type,
			    igraph_integer_t n, igraph_real_t p,
			    igraph_bool_t directed, igraph_bool_t loops);
int igraph_erdos_renyi_game_gnp(igraph_t *graph, igraph_integer_t n, igraph_real_t p,
				igraph_bool_t directed, igraph_bool_t loops);
int igraph_erdos_renyi_game_gnm(igraph_t *graph, igraph_integer_t n, igraph_real_t m,
				igraph_bool_t directed, igraph_bool_t loops);
int igraph_degree_sequence_game(igraph_t *graph, const igraph_vector_t *out_deg,
				const igraph_vector_t *in_deg, 
				igraph_degseq_t method);
int igraph_growing_random_game(igraph_t *graph, igraph_integer_t n, 
			       igraph_integer_t m, igraph_bool_t directed, igraph_bool_t citation);
int igraph_barabasi_aging_game(igraph_t *graph, 
			       igraph_integer_t nodes,
			       igraph_integer_t m,
			       const igraph_vector_t *outseq,
			       igraph_bool_t outpref,
			       igraph_real_t pa_exp,
			       igraph_real_t aging_exp,
			       igraph_integer_t aging_bin,
			       igraph_real_t zero_deg_appeal,
			       igraph_real_t zero_age_appeal,
			       igraph_real_t deg_coef,
			       igraph_real_t age_coef,
			       igraph_bool_t directed);
int igraph_recent_degree_game(igraph_t *graph, igraph_integer_t n,
			      igraph_real_t power,
			      igraph_integer_t window,
			      igraph_integer_t m,  
			      const igraph_vector_t *outseq,
			      igraph_bool_t outpref,
			      igraph_real_t zero_appeal,
			      igraph_bool_t directed);
int igraph_recent_degree_aging_game(igraph_t *graph,
				    igraph_integer_t nodes,
				    igraph_integer_t m, 
				    const igraph_vector_t *outseq,
				    igraph_bool_t outpref,
				    igraph_real_t pa_exp,
				    igraph_real_t aging_exp,
				    igraph_integer_t aging_bin,
				    igraph_integer_t window,
				    igraph_real_t zero_appeal,
				    igraph_bool_t directed);
int igraph_callaway_traits_game (igraph_t *graph, igraph_integer_t nodes, 
				 igraph_integer_t types, igraph_integer_t edges_per_step, 
				 igraph_vector_t *type_dist,
				 igraph_matrix_t *pref_matrix,
				 igraph_bool_t directed);
int igraph_establishment_game(igraph_t *graph, igraph_integer_t nodes,
			      igraph_integer_t types, igraph_integer_t k,
			      igraph_vector_t *type_dist,
			      igraph_matrix_t *pref_matrix,
			      igraph_bool_t directed);
int igraph_grg_game(igraph_t *graph, igraph_integer_t nodes,
		    igraph_real_t radius, igraph_bool_t torus,
		    igraph_vector_t *x, igraph_vector_t *y);
int igraph_preference_game(igraph_t *graph, igraph_integer_t nodes,
			   igraph_integer_t types, igraph_vector_t *type_dist,
			   igraph_matrix_t *pref_matrix,
			   igraph_vector_t *node_type_vec,
			   igraph_bool_t directed, igraph_bool_t loops);
int igraph_asymmetric_preference_game(igraph_t *graph, igraph_integer_t nodes,
				      igraph_integer_t types,
				      igraph_matrix_t *type_dist_matrix,
				      igraph_matrix_t *pref_matrix,
				      igraph_vector_t *node_type_in_vec,
				      igraph_vector_t *node_type_out_vec,
				      igraph_bool_t loops);

int igraph_rewire_edges(igraph_t *graph, igraph_real_t prob);
int igraph_watts_strogatz_game(igraph_t *graph, igraph_integer_t dim,
			       igraph_integer_t size, igraph_integer_t nei,
			       igraph_real_t p);

int igraph_lastcit_game(igraph_t *graph, 
			igraph_integer_t nodes, igraph_integer_t edges_per_node, 
			igraph_integer_t agebins,
			const igraph_vector_t *preference, igraph_bool_t directed);

int igraph_cited_type_game(igraph_t *graph, igraph_integer_t nodes,
			   const igraph_vector_t *types,
			   const igraph_vector_t *pref,
			   igraph_integer_t edges_per_step,
			   igraph_bool_t directed);

int igraph_citing_cited_type_game(igraph_t *graph, igraph_integer_t nodes,
				  const igraph_vector_t *types,
				  const igraph_matrix_t *pref,
				  igraph_integer_t edges_per_step,
				  igraph_bool_t directed);

int igraph_forest_fire_game(igraph_t *graph, igraph_integer_t nodes,
			    igraph_real_t fw_prob, igraph_real_t bw_factor,
			    igraph_integer_t ambs, igraph_bool_t directed);

__END_DECLS

#endif
