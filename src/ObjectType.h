//
// Created by bekzat on 29.03.23.
//

#include <unordered_map>

namespace Stella{
    class ObjectType {
    public:
        MyTypeTag typeTag;
        int data = -1;

        std::vector<ObjectType> params = {};
        std::vector<ObjectType> returns = {};

        ObjectType(){
            typeTag = MyTypeTag::UndefinedTag;
        }

        ObjectType(MyTypeTag tag){
            typeTag = tag;
        }

        ObjectType(MyTypeTag tag, int value){
            typeTag = tag;
            data = value;
        }

        ObjectType& operator= (const ObjectType &other){
            typeTag = other.typeTag;
            params = other.params;
            returns = other.returns;
            return *this;
        }

        bool operator==(const ObjectType& other){
            return !(*this != other);
        }

        bool operator!=(const ObjectType& other){
            if(typeTag != other.typeTag) return true;
            if(params.size() != other.params.size()) return true;
            if(returns.size() != other.returns.size()) return true;
            if(typeTag == MyTypeTag::SumTypeTag){
                return params[0] != other.params[0] && params[1] != other.params[1];
            }
            for(int i = 0; i < params.size(); i++){
                if(params[i] != other.params[i]){
                    return true;
                }
            }
            for(int i = 0; i < returns.size(); i++){
                if(returns[i] != other.returns[i]){
                    return true;
                }
            }
            return false;
        }


    };
}