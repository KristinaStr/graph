#include <catch.hpp>
#include <sstream>

#include "graph.hpp"

TEST_CASE ("Create")
{
  graph_t graph;
  REQUIRE( graph_2.size_V() == 0 );
}

TEST_CASE ("Test my graph")
{
  graph_t graph(4);
	std::string input{
		"0 1 0 0 \n"
		"1 0 1 1 \n"
		"0 0 0 0 \n"
		"0 0 0 0 \n"
	};
	std::istringstream stream (input);
	graph.read(stream);
	std::vector<unsigned> result;
	result = graph.dfs(1);
	std::ostringstream output;
	graph.res_graph(output, result);
  
  std::string res_out = "0";
  REQUIRE( res_out == output.str() );
}

