#include "../../includes/utils/Tratament.hpp"

Utils::Tratament::Tratament()
{

}

std::string Utils::Tratament::serializeJson( pqxx::result data, std::string* columns )
{
	rapidjson::Document document;
	document.SetObject();
	rapidjson::Value array(rapidjson::kArrayType);
	rapidjson::Document::AllocatorType& allocator = document.GetAllocator();

 
    for(
        int index = 0;
        index < data.size(); 
        ++index
    ) {
        pqxx::row const row_index = data[index];

        for(
          int row = 0; 
          row < row_index.size(); 
          ++row 
          ) {
            const char* field = row_index[row].c_str();
            const char*  column = columns[row].c_str();

            document.AddMember(
              rapidjson::StringRef(column),  
              rapidjson::Value(field, allocator), 
              allocator
            );
        }
    }


    // for( auto data_row : data )
    // {
    //     ++index;
    //     for(auto row : data_row )
    //     {
    //         document.AddMember("a", data_row, allocator);
    //     }
    // }

      // for( auto const &row : data )
      // {
      //     for (auto const &field : row)
      //     {
      //     std::cout << field.c_str() << '\t' << std::endl;
      //     } ;
      // };

 
	rapidjson::StringBuffer strbuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
	document.Accept(writer);
 
	return strbuf.GetString();
}

Utils::Tratament::~Tratament()
{

}