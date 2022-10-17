#include "ChainHash.h"
#include "Block.h"
using namespace std;
const int StructureSize = 1000;
// template<typename TK, typename TV>

class BlockChain{
   private:
   ChainHash<string, Block*> Structure; // O(n)
   string LastHashId = "1";
   public:
   BlockChain(){
      Block* block =  new Block(nullptr,LastHashId);
      LastHashId = block->setHashCentinel();
      Structure.insert(block->getHash(),block);
   // Structure = ChainHash<string,Block*>(StructureSize);

   }
   string addBlock(Transaction* _data)
   {
    Block* block =  new Block(_data,LastHashId);
    LastHashId = block->generateHash();
    Structure.insert(block->getHash(), block);
    return block->getHash();
   }

   Block* getBlockByHash(string hash) //O(K)
   {
      Block* block = Structure.get(hash);
      // cout << block->   ();
            // cout << block->get_Data()->getCantidadSoles();
      return block;
      // cout << block->data << endl;
   }

};