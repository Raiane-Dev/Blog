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
 
	rapidjson::StringBuffer strbuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
	document.Accept(writer);
 
	return strbuf.GetString();
}


std::string Utils::Tratament::serializeCrypt( std::string pass )
{

  const int works = static_cast<int>(*std::getenv("CRYPT_WORK_FACTOR"));
  Botan::AutoSeeded_RNG seed;
  std::string hash = Botan::generate_bcrypt(pass, seed, works);

  return hash;
}

bool Utils::Tratament::verifyCrypt( std::string pass, std::string hash )
{
  bool verify_pass = Botan::check_bcrypt(pass, hash);

  return verify_pass;
}

Utils::Tratament::~Tratament()
{

}