#include "engine.h"

QVector<Engine_SN_Range> Engine::all_engine_sn = QVector<Engine_SN_Range>(8);

Engine::Engine(const QString &engineSN_input)
{
    setEngineSN(engineSN_input);
    all_engine_sn[0].e_ranges->push_back(new Range("900000", "900999"));
    all_engine_sn[0].e_type = "GE90";

    all_engine_sn[1].e_ranges->push_back(new Range("901000", "901999"));
    all_engine_sn[1].e_ranges->push_back(new Range("906000", "906999"));
    all_engine_sn[1].e_ranges->push_back(new Range("907000", "907999"));
    all_engine_sn[1].e_type = "GE90_1";

    all_engine_sn[2].e_ranges->push_back(new Range("731000", "731999"));
    all_engine_sn[2].e_type = "CFM56_5A";

    all_engine_sn[3].e_ranges->push_back(new Range("569000", "569999"));
    all_engine_sn[3].e_ranges->push_back(new Range("575000", "575999"));
    all_engine_sn[3].e_ranges->push_back(new Range("577000", "577999"));
    all_engine_sn[3].e_ranges->push_back(new Range("643000", "643999"));
    all_engine_sn[3].e_ranges->push_back(new Range("697000", "697999"));
    all_engine_sn[3].e_ranges->push_back(new Range("699000", "699999"));
    all_engine_sn[3].e_ranges->push_back(new Range("779000", "779999"));
    all_engine_sn[3].e_type = "CFM56_5B";

    all_engine_sn[4].e_ranges->push_back(new Range("567000", "567999"));
    all_engine_sn[4].e_ranges->push_back(new Range("740000", "740999"));
    all_engine_sn[4].e_ranges->push_back(new Range("741000", "741999"));
    all_engine_sn[4].e_type = "CFM56_5C";

    all_engine_sn[5].e_ranges->push_back(new Range("550000", "550999"));
    all_engine_sn[5].e_type = "GP7200";

    all_engine_sn[6].e_ranges->push_back(new Range("811000", "811999"));
    all_engine_sn[6].e_type = "CF6_80_E1";

    all_engine_sn[7].e_ranges->push_back(new Range("702000", "702999"));
    all_engine_sn[7].e_type = "CF6_80_C2";
    setEngineType();
}

void Engine::setEngineSN(const QString &engineSN)
{
    for (int i = 0; i < engineSN.size(); i++)
        if (!isdigit(engineSN.toStdString().at(i)))
            engine_sn = "Error";
    engine_sn = engineSN;
}

// Defines engine type and attributes str
void Engine::setEngineType()
{
    for (int i = 0; i < all_engine_sn.size(); i++)
    {
        for (int j = 0; j < all_engine_sn[i].e_ranges->size(); j++)
        {
            if (engine_sn.toInt() >= all_engine_sn[i].e_ranges->at(j)->low_value.toInt()
                    && engine_sn.toInt() <= all_engine_sn[i].e_ranges->at(j)->high_value.toInt())
            {
                engine_type = (engineType)i;
                engine_type_str = all_engine_sn[i].e_type;
                return ;
            }
        }
    }
    engine_type = engineType::Error;
    engine_type_str = "Error_SN";
    return ;
}
