#include <iostream>
#include <sstream>
#include <vector>
#include<string>
#include<stdexcept>

class graph_t
{
private: 
	unsigned V;
	bool ** pole;
public:
	graph_t(unsigned N) 
	{
		V = N;
		pole = new bool * [V];
		for (std::size_t i = 0; i < V; ++i)
		{
			pole[i] = new bool [V];
		}
	}

	graph_t()
	{
		V = 0;
		pole = nullptr;
	}

	graph_t & operator=(graph_t const &) = delete;

	graph_t(graph_t const &) = delete;

	~graph_t() 
	{
		for (std::size_t i = 0; i < V; ++i)
		{
			delete[] pole[i];
		}
		delete[] pole;
	}

	unsigned size_V() 
	{
		return V;
	}

	void read(std::istringstream& stream);

private:
	void help(unsigned index, std::vector<unsigned> * used, std::vector<unsigned> * res)
	{
		(*used)[index] = true;
		(*res).push_back(index + 1);
		for (unsigned j = 0; j < V; j++) {
			if (pole[index][j])
			{
				if (!(*used)[j])
				{
					help(j, used, res);
				}
			}
		}
	}

public:
	void res_graph(std::ostream & ostream, std::vector<unsigned> res);

	std::vector<unsigned> dfs(unsigned index) 
	{
		std::vector<unsigned> used, res;
		used.reserve(V);
		for (unsigned i = 0; i < V; i++) {
			used.push_back(false);
		}
		help(index, &used, &res);
		return res;
	}
};

void graph_t::read(std::istringstream& stream)
{
	for (std::size_t i = 0; i < V; i++)
	{
		for (std::size_t j = 0; j < V; j++)
		{
			unsigned a;
			stream >> a;
			if (a==1 || a==0)
			{
				pole[i][j] = a;
			}
			else throw std::invalid_argument("Error input");
		}
		if (pole[i][i] != 0) 
		{
			throw std::invalid_argument("Error input");
		}
	}
}

void graph_t::res_graph(std::ostream & ostream, std::vector<unsigned> res)
{
	for (unsigned i : res)
	{
		ostream << i << ' ';
	}

}
