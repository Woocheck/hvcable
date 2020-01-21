#include "./grid.h"
#include <armadillo>

std::complex<double> Model::strToComplex( std::string value )
{
    std::istringstream is('(' + value + ')');
    std::complex<double> conwertedValue;
    is >> conwertedValue;

    return conwertedValue;
}

void Model::reloadModel()
{
    loadGraphs();
    loadNodes();
    calculateAdmitanceMatrix();
    
   
}

void Model::loadGraphs()
{
    InputData graphFile( "./graphs.txt");
    auto graphString { std::make_shared<InputData>( graphFile ) };

    for( auto rawGraph : graphString->getData() )
    {
        _elements[ std::stoi( rawGraph.at( 0 ) )].setElementNumber( std::stoi( rawGraph.at( 0 ) ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setName( rawGraph.at( 1 ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setVoltage( std::atof( rawGraph.at( 2 ).c_str() ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setCrossection( std::atof( rawGraph.at( 3 ).c_str() ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setResistance( std::atof( rawGraph.at( 4 ).c_str() ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setReactance( std::atof( rawGraph.at( 5 ).c_str() ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setSusceptance( std::atof( rawGraph.at( 6 ).c_str() ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setLenght( std::atof( rawGraph.at( 7 ).c_str() ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setNominalId( std::atof( rawGraph.at( 8 ).c_str() ) );   
    }
}
void Model::loadNodes()
{
    InputData nodesFile("./nodes.txt");
    auto nodesString { std::make_shared<InputData>( nodesFile )};

    for( auto rawNode : nodesString->getData() )
    {
        _nodes[ std::stoi( rawNode.at( 0 ) )].setNumber( std::stoi( rawNode.at( 0 ) ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setName(rawNode.at( 1 ));
        _nodes[ std::stoi( rawNode.at( 0 ) )].setParentNumber( std::stoi( rawNode.at( 2 ) ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setP( std::atof( rawNode.at( 3 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setQ( std::atof( rawNode.at( 4 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setVoltageModule( std::atof( rawNode.at( 5 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setVoltageArgument( std::atof( rawNode.at( 6 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setCategory( std::stoi( rawNode.at( 7 ) ) );
    }
}
void Model::calculateAdmitanceMatrix()
{
    auto matrixSize { _nodes.size() };
    _admitanceMatrix.resize( matrixSize, matrixSize );
    for(auto graph : _elements )
    {
        _admitanceMatrix.at( graph.second.)
    }
    
    for( int i{0}; i< matrixSize; i++)
    {
        
    }
}


