#include <QString>
#include <QtTest>
#include "row.h"
#include "util.h"
#include <iostream>

#include "insert_range_moving_the_others.h"
class Cluster_LegalizationTest : public QObject
{
    Q_OBJECT

    void __print_row(Overlap_Removal::Row & r, int resolution = 10);
public:
    Cluster_LegalizationTest();

    bool verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(Overlap_Removal::Row & r);

private Q_SLOTS:
    void criar_uma_linha_vazia();
    void inserir_fora_dos_limites();
    void inserir_uma_celula_em_um_cluster();
    void inserir_uma_celula_que_ocupe_um_cluster_inteiro();
    void inserir_uma_celula_no_inicio_do_cluster();
    void inserir_uma_celula_no_fim_do_cluster();
    void inserir_uma_celula_no_meio_do_cluster();
    void inserir_no_inicio_e_no_fim_deixando_um_espaco_no_meio();
    void inserir_no_inicio_no_fim_e_no_meio_sem_clusterizar();
    void inserir_no_inicio_no_fim_clusterizando();
    void inserir_no_fim_e_no_inicio_clusterizando();
    void inserir_de_uma_a_10_celulas_sem_clusterizar_e_com_espaco_nos_dois_cantos();
    void inserir_de_uma_a_10_celulas_sem_clusterizar_grudado_no_inicio();
    void inserir_de_uma_a_10_celulas_sem_clusterizar_grudado_no_fim();
    void inserir_em_um_lugar_ja_ocupado();
    void inserir_e_retornar_o_iterador_para_o_cluster();
    void clusterizar_com_o_cluster_da_direita();
    void remover_uma_celula_do_fim_de_um_cluster();
    void remover_uma_celula_do_inicio_de_um_cluster();
    void remover_uma_celula_do_meio_de_um_cluster();
    void remover_uma_celula_que_esta_sozinha_no_cluster();
    void remover_uma_celula_que_esta_sozinha_em_um_cluster_grudado_no_inicio_da_linha();
    void remover_uma_celula_que_esta_sozinha_em_um_cluster_grudado_no_fim_da_linha();
    void remover_uma_celula_que_esta_sozinha_em_um_cluster_que_ocupa_toda_a_linha();
    void remover_uma_celula_do_inicio_de_um_cluster_grudado_no_inicio_da_linha();
    void remover_uma_celula_do_fim_de_um_cluster_grudado_no_fim_da_linha();
    void remover_uma_celula_do_inicio_de_um_cluster_que_ocupa_toda_a_linha();
    void remover_uma_celula_do_fim_de_um_cluster_que_ocupa_toda_a_linha();
    void remover_uma_celula_do_meio_de_um_cluster_que_ocupa_toda_a_linha();
    void obter_limites_do_cluster();
    void obter_posicoes_mais_proximas_sem_passar_por_cima();
    void obter_posicoes_mais_proximas_passando_por_cima_de_ranges_ocupados();
    void obter_posicoes_mais_proximas_se_a_celula_comeca_antes_e_termina_depois_de_um_cluster();
    void obter_posicoes_mais_proximas_se_a_celula_cabe_inteira_dentro_de_um_cluster();
    void obter_posicoes_mais_proximas_se_a_celula_ocupa_o_mesmo_espaco_do_cluster();
    void obter_posicoes_mais_proximas_se_a_celula_tem_o_mesmo_tamanho_do_cluster();
    void obter_posicao_mais_proxima_se_a_celula_cabe_onde_quer_entrar();
    void obter_posicao_mais_proxima_se_a_celula_cabe_certinho_no_cluster_da_esquerda();
    void obter_posicao_mais_proxima_se_a_celula_cabe_certinho_no_cluster_da_direita();


    void obter_posicoes_mais_proximas_do_espaco_livre_permitindo_x_porcento_de_overlap();
    void obter_posicoes_mais_proximas_do_espaco_livre_permitindo_x_porcento_de_overlap_movendo_no_maximo_um_cluster();
    void obter_posicoes_mais_proximas_do_espaco_ocupado_permitindo_x_porcento_de_overlap();
    void obter_posicoes_mais_proximas_do_espaco_ocupado_permitindo_x_porcento_de_overlap_movendo_no_maximo_um_cluster();
    void obter_posicoes_mais_proximas_do_espaco_ocupado_permitindo_x_porcento_de_overlap_movendo_no_maximo_um_cluster_com_overlap_antes_e_depois();






    void mover_um_cluster_para_direita_e_nao_clusterizar();
    void mover_um_cluster_para_direita_e_clusterizar();
    void mover_um_cluster_para_esquerda_e_nao_clusterizar();
    void mover_um_cluster_para_esquerda_e_clusterizar();

    void mover_o_cluster_do_fim_para_a_esquerda();
    void mover_o_cluster_do_inicio_para_a_direita();

    void impedir_que_mova_um_cluster_para_a_direita_no_limite_da_linha();
    void impedir_que_mova_um_cluster_para_a_esquerda_no_inicio_da_linha();
    void impedir_que_tente_mover_um_cluster_com_um_passo_menor_que_1();
    void impedir_que_mova_para_a_direita_sem_espaco_livre();
    void impedir_que_mova_para_a_esquerda_sem_espaco_livre();
    void impedir_que_mova_um_cluster_livre();

    void encontrando_um_cluster_com_base_em_um_range();
    void encontrando_um_cluster_com_base_em_uma_coordenada();
    void criar_um_range_invalido();
    void mover_um_cluster_sem_precisar_passar_por_todos_do_cluster();
    void referencia_range_para_cluster();
    void clone_de_linha();
    void insercao_em_um_cluster_especifico();

    void espaco_a_direita();
    void espaco_a_esquerda();
    void espaco_total_a_esquerda();
    void espaco_total_a_direita();

    void encontrar_celulas_da_direita_e_esquerda();
    void encontrar_celulas_da_direita_e_esquerda2();


    void quebrar_cluster();

    void espaco_livre_na_linha();


    void inserir_range_movendo_os_outros_se_necessario();
    void inserir_range_movendo_os_outros_se_necessario_no_limite_de_espaco();
    void inserir_range_movendo_os_outros_se_necessario_no_limite_de_faltando_1_na_direita();
    void inserir_range_movendo_os_outros_se_necessario_no_limite_de_faltando_1_na_esquerda();
    void inserir_range_movendo_os_outros_se_necessario_no_limite_de_faltando_1_em_cada_lado();


    void inserir_range_movendo_os_outros_se_necessario_o_range_eh_o_menor();
    void inserir_range_movendo_os_outros_se_necessario_o_range_eh_o_menor2();
    void inserir_range_movendo_os_outros_soh_para_a_direita();


    void mover_soh_para_a_esquerda_no_fim_da_linha();
    void mover_soh_para_a_esquerda_no_fim_da_linha_quebrando();

    void mover_soh_para_a_direita_no_inicio_da_linha();
    void mover_soh_para_a_direita_no_inicio_da_linha_quebrando();

    void mover_soh_para_a_direita_mantendo_um_na_esquerda_no_inicio_da_linha();





};

Cluster_LegalizationTest::Cluster_LegalizationTest()
{
}

bool Cluster_LegalizationTest::verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(Overlap_Removal::Row &r)
{
    for(Cluster_Iterator it = r.first_cluster_iterator(); it != r.not_valid_iterator(); it++)
    {
        for(std::list<Overlap_Removal::Range_In_Cluster>::const_iterator it2 = it->ranges().begin(); it2 != it->ranges().end(); it2++)
        {
            if(it2->cluster() != it)
                return false;
        }
    }
    return true;
}

void Cluster_LegalizationTest::criar_uma_linha_vazia()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    QVERIFY(r.begin() == begin);
    QVERIFY(r.end() == end);
    QVERIFY2(r.number_of_clusters() == 1, "Só pode ter um Cluster");

    const Overlap_Removal::Cluster & c = r.cluster(0);
    QVERIFY2(c.begin() == r.begin() && c.end() == r.end(), "O cluster deve representar todo o range da linha");
    QVERIFY2(c.is_free_space(), "O cluster deve representar um espaço livre");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_fora_dos_limites()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);

    EXCEPT_THROW(r.insert_range(-30, -5, 1), Overlap_Removal::Out_of_Bounds);
    EXCEPT_THROW(r.insert_range(-30, 10, 2), Overlap_Removal::Out_of_Bounds);
    EXCEPT_THROW(r.insert_range(990, 1000, 3), Overlap_Removal::Out_of_Bounds);
    EXCEPT_THROW(r.insert_range(1000, 1100, 4), Overlap_Removal::Out_of_Bounds);
    EXCEPT_THROW(r.insert_range(-5, 1005, 5), Overlap_Removal::Out_of_Bounds);
    EXCEPT_NOT_THROW(r.insert_range(10, 10, 7), Overlap_Removal::Out_of_Bounds);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));

}

void Cluster_LegalizationTest::inserir_uma_celula_em_um_cluster()
{
    {
        int begin = 0;
        int end = 999;
        int cell_id = 666;
        Overlap_Removal::Row r(begin, end);
        Cluster_Iterator theCluster = r.insert_range(begin, end, cell_id);
        QVERIFY2(theCluster->has(cell_id), "A célula deve estar no cluster");
        QVERIFY2(theCluster->number_of_ranges() == 1, "A célula deve estar no cluster sozinha");
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    {
        int begin = 0;
        int end = 999;
        std::pair<int, int> cell1(begin, 100);
        std::pair<int, int> cell2(cell1.second+1, end);
        int cell1_id = 666;
        int cell2_id = 700;
        Overlap_Removal::Row r(begin, end);
        Cluster_Iterator primeiro_cluster = r.insert_range(cell1.first, cell1.second, cell1_id);
        Cluster_Iterator segundo_cluster = r.insert_range(cell2.first, cell2.second, cell2_id);
        QVERIFY2(segundo_cluster->has(cell1_id), "A célula deve estar no cluster");
        QVERIFY2(segundo_cluster->has(cell2_id), "A célula deve estar no cluster");
        QVERIFY2(segundo_cluster->number_of_ranges() == 2, "Deve ter duas células no cluster");
        QVERIFY(&(*primeiro_cluster) == &(*segundo_cluster));
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
}

void Cluster_LegalizationTest::inserir_uma_celula_que_ocupe_um_cluster_inteiro()
{
    int begin = 0;
    int end = 999;
    int cell_id  = 1;
    Overlap_Removal::Row r(begin, end);
    Cluster_Iterator o_cluster = r.insert_range(begin, end, cell_id);

    QVERIFY2(r.number_of_clusters() == 1, "Só pode ter um Cluster");
    QVERIFY2(o_cluster->begin() == r.begin() && o_cluster->end() == r.end(), "O cluster deve representar todo o range da linha");
    QVERIFY2(!o_cluster->is_free_space(), "O cluster deve representar um espaço ocupado");
    QVERIFY2(&(*o_cluster) == &r.cluster(0), "O cluster deve ser o primeiro cluster");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_uma_celula_no_inicio_do_cluster()
{
    int begin = 0;
    int end = 999;
    int cell_end = 10;
    int cell_id  = 1;
    Overlap_Removal::Row r(begin, end);
    r.insert_range(begin, cell_end, cell_id);

    QVERIFY2(r.number_of_clusters() == 2, "Deve ter dois clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.begin() == r.begin() && c1.end() == cell_end, "O cluster deve representar o range ocupado pela célula");
    QVERIFY2(!c1.is_free_space(), "O cluster deve representar um espaço ocupado");

    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    QVERIFY2(c2.begin() == cell_end + 1 && c2.end() == end, "O cluster deve representar o range livre na linha");
    QVERIFY2(c2.is_free_space(), "O cluster deve representar um espaço livre");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_uma_celula_no_fim_do_cluster()
{
    int begin = 0;
    int end = 999;
    int cell_begin = 900;
    int cell_id  = 1;
    Overlap_Removal::Row r(begin, end);
    r.insert_range(cell_begin, end, cell_id);

    QVERIFY2(r.number_of_clusters() == 2, "Deve ter dois clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.begin() == r.begin() && c1.end() == cell_begin - 1, "O cluster deve representar o range livre na linha");
    QVERIFY2(c1.is_free_space(), "O cluster deve representar um espaço livre");

    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    QVERIFY2(c2.begin() == cell_begin && c2.end() == end, "O cluster deve representar o range ocupado pela célula");
    QVERIFY2(!c2.is_free_space(), "O cluster deve representar um espaço ocupado");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_uma_celula_no_meio_do_cluster()
{
    int begin = 0;
    int end = 999;
    int cell_begin = 200;
    int cell_end = 299;
    int cell_id  = 1;
    Overlap_Removal::Row r(begin, end);
    r.insert_range(cell_begin, cell_end, cell_id);

    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.begin() == r.begin() && c1.end() == cell_begin - 1, "O cluster deve representar um range livre na linha");
    QVERIFY2(c1.is_free_space(), "O cluster deve representar um espaço livre");

    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    QVERIFY2(c2.begin() == cell_begin && c2.end() == cell_end, "O cluster deve representar o range ocupado pela célula");
    QVERIFY2(!c2.is_free_space(), "O cluster deve representar um espaço ocupado");

    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    QVERIFY2(c3.begin() == cell_end+1 && c3.end() == end, "O cluster deve representar um range livre na linha");
    QVERIFY2(c3.is_free_space(), "O cluster deve representar um espaço livre");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_no_inicio_e_no_fim_deixando_um_espaco_no_meio()
{
    int begin = 0;
    int end = 999;
    int cell1_end = 299;
    int cell2_begin = 800;
    int cell1_id  = 1;
    int cell2_id = 2;
    Overlap_Removal::Row r(begin, end);
    r.insert_range(begin, cell1_end, cell1_id);
    r.insert_range(cell2_begin, end, cell2_id);


    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.begin() == r.begin() && c1.end() == cell1_end, "O cluster deve representar o range ocupado pela célula");
    QVERIFY2(!c1.is_free_space(), "O cluster deve representar um espaço ocupado");

    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    QVERIFY2(c2.begin() == cell1_end + 1 && c2.end() == cell2_begin -1, "O cluster deve representar o range livre na linha");
    QVERIFY2(c2.is_free_space(), "O cluster deve representar um espaço livre");

    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    QVERIFY2(c3.begin() == cell2_begin && c3.end() == end, "O cluster deve representar o range ocupado pela célula");
    QVERIFY2(!c3.is_free_space(), "O cluster deve representar um espaço ocupado");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_no_inicio_no_fim_e_no_meio_sem_clusterizar()
{
    int begin = 0;
    int end = 999;
    std::pair<int, int> cell1(begin, 99);
    std::pair<int, int> cell2(500, 599);
    std::pair<int, int> cell3(900, 999);
    Overlap_Removal::Row r(begin, end);
    r.insert_range(cell1.first, cell1.second, 1);
    r.insert_range(cell3.first, cell3.second, 3);
    r.insert_range(cell2.first, cell2.second, 2);

    QVERIFY2(r.number_of_clusters() == 5, "Deve ter cinco clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    const Overlap_Removal::Cluster & c4 = r.cluster(3);
    const Overlap_Removal::Cluster & c5 = r.cluster(4);

    QVERIFY(!c1.is_free_space());
    QVERIFY(c2.is_free_space());
    QVERIFY(!c3.is_free_space());
    QVERIFY(c4.is_free_space());
    QVERIFY(!c5.is_free_space());
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));

}

void Cluster_LegalizationTest::inserir_no_inicio_no_fim_clusterizando()
{
    int begin = 0;
    int end = 999;
    int cell1_end = 299;
    int cell2_begin = 300;
    int cell1_id  = 1;
    int cell2_id = 2;
    Overlap_Removal::Row r(begin, end);
    r.insert_range(begin, cell1_end, cell1_id);
    r.insert_range(cell2_begin, end, cell2_id);


    QVERIFY2(r.number_of_clusters() == 1, "Deve ter um cluster só");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.begin() == r.begin() && c1.end() == end, "O cluster deve representar todo o range da linha");
    QVERIFY2(!c1.is_free_space(), "O cluster deve representar um espaço ocupado");
    QVERIFY2(c1.number_of_ranges() == 2, "O cluster deve possuir duas células");
    QVERIFY2(c1.has(cell1_id), "A célula de id = 'cell1_id' deve ester no cluster");
    QVERIFY2(c1.has(cell2_id), "A célula de id = 'cell2_id' deve ester no cluster");
    QVERIFY2(!c1.has(3), "A célula de id = 3 não deve ester no cluster");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_no_fim_e_no_inicio_clusterizando()
{
    int begin = 0;
    int end = 999;
    int cell1_end = 299;
    int cell2_begin = 300;
    int cell1_id  = 1;
    int cell2_id = 2;
    Overlap_Removal::Row r(begin, end);
    r.insert_range(cell2_begin, end, cell2_id);
    r.insert_range(begin, cell1_end, cell1_id);

    QVERIFY2(r.number_of_clusters() == 1, "Deve ter um cluster só");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.begin() == r.begin() && c1.end() == end, "O cluster deve representar todo o range da linha");
    QVERIFY2(!c1.is_free_space(), "O cluster deve representar um espaço ocupado");
    QVERIFY2(c1.number_of_ranges() == 2, "O cluster deve possuir duas células");
    QVERIFY2(c1.has(cell1_id), "A célula de id = 'cell1_id' deve ester no cluster");
    QVERIFY2(c1.has(cell2_id), "A célula de id = 'cell2_id' deve ester no cluster");
    QVERIFY2(!c1.has(3), "A célula de id = 3 não deve ester no cluster");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_de_uma_a_10_celulas_sem_clusterizar_e_com_espaco_nos_dois_cantos()
{
    int begin = 0;
    int end = 1999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(50, 99);
    std::pair<int, int> cell2(200, 299);
    std::pair<int, int> cell3(400, 499);
    std::pair<int, int> cell4(600, 699);
    std::pair<int, int> cell5(800, 899);
    std::pair<int, int> cell6(1000, 1099);
    std::pair<int, int> cell7(1200, 1299);
    std::pair<int, int> cell8(1400, 1499);
    std::pair<int, int> cell9(1600, 1699);
    std::pair<int, int> cell10(1800, 1899);

    QVERIFY(r.number_of_clusters() == 1);
    r.insert_range(cell1, 1);
    QVERIFY(r.number_of_clusters() == 3);
    r.insert_range(cell2, 2);
    QVERIFY(r.number_of_clusters() == 5);
    r.insert_range(cell3, 3);
    QVERIFY(r.number_of_clusters() == 7);
    r.insert_range(cell4, 4);
    QVERIFY(r.number_of_clusters() == 9);
    r.insert_range(cell5, 5);
    QVERIFY(r.number_of_clusters() == 11);
    r.insert_range(cell6, 6);
    QVERIFY(r.number_of_clusters() == 13);
    r.insert_range(cell7, 7);
    QVERIFY(r.number_of_clusters() == 15);
    r.insert_range(cell8, 8);
    QVERIFY(r.number_of_clusters() == 17);
    r.insert_range(cell9, 9);
    QVERIFY(r.number_of_clusters() == 19);
    r.insert_range(cell10, 10);
    QVERIFY(r.number_of_clusters() == 21);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));

}

void Cluster_LegalizationTest::inserir_de_uma_a_10_celulas_sem_clusterizar_grudado_no_inicio()
{
    int begin = 0;
    int end = 1999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 99);
    std::pair<int, int> cell2(200, 299);
    std::pair<int, int> cell3(400, 499);
    std::pair<int, int> cell4(600, 699);
    std::pair<int, int> cell5(800, 899);
    std::pair<int, int> cell6(1000, 1099);
    std::pair<int, int> cell7(1200, 1299);
    std::pair<int, int> cell8(1400, 1499);
    std::pair<int, int> cell9(1600, 1699);
    std::pair<int, int> cell10(1800, 1899);

    QVERIFY(r.number_of_clusters() == 1);
    r.insert_range(cell1, 1);
    QVERIFY(r.number_of_clusters() == 2);
    r.insert_range(cell2, 2);
    QVERIFY(r.number_of_clusters() == 4);
    r.insert_range(cell3, 3);
    QVERIFY(r.number_of_clusters() == 6);
    r.insert_range(cell4, 4);
    QVERIFY(r.number_of_clusters() == 8);
    r.insert_range(cell5, 5);
    QVERIFY(r.number_of_clusters() == 10);
    r.insert_range(cell6, 6);
    QVERIFY(r.number_of_clusters() == 12);
    r.insert_range(cell7, 7);
    QVERIFY(r.number_of_clusters() == 14);
    r.insert_range(cell8, 8);
    QVERIFY(r.number_of_clusters() == 16);
    r.insert_range(cell9, 9);
    QVERIFY(r.number_of_clusters() == 18);
    r.insert_range(cell10, 10);
    QVERIFY(r.number_of_clusters() == 20);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_de_uma_a_10_celulas_sem_clusterizar_grudado_no_fim()
{
    int begin = 0;
    int end = 1899;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(50, 99);
    std::pair<int, int> cell2(200, 299);
    std::pair<int, int> cell3(400, 499);
    std::pair<int, int> cell4(600, 699);
    std::pair<int, int> cell5(800, 899);
    std::pair<int, int> cell6(1000, 1099);
    std::pair<int, int> cell7(1200, 1299);
    std::pair<int, int> cell8(1400, 1499);
    std::pair<int, int> cell9(1600, 1699);
    std::pair<int, int> cell10(1800, 1899);

    QVERIFY(r.number_of_clusters() == 1);
    r.insert_range(cell1, 1);
    QVERIFY(r.number_of_clusters() == 3);
    r.insert_range(cell2, 2);
    QVERIFY(r.number_of_clusters() == 5);
    r.insert_range(cell3, 3);
    QVERIFY(r.number_of_clusters() == 7);
    r.insert_range(cell4, 4);
    QVERIFY(r.number_of_clusters() == 9);
    r.insert_range(cell5, 5);
    QVERIFY(r.number_of_clusters() == 11);
    r.insert_range(cell6, 6);
    QVERIFY(r.number_of_clusters() == 13);
    r.insert_range(cell7, 7);
    QVERIFY(r.number_of_clusters() == 15);
    r.insert_range(cell8, 8);
    QVERIFY(r.number_of_clusters() == 17);
    r.insert_range(cell9, 9);
    QVERIFY(r.number_of_clusters() == 19);
    r.insert_range(cell10, 10);
    QVERIFY(r.number_of_clusters() == 20);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::inserir_em_um_lugar_ja_ocupado()
{
    { // em um cluster livre mas não cabe
        int begin = 0;
        int end = 1899;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(50, 99);
        std::pair<int, int> cell2(200, 299);
        std::pair<int, int> cell3(150, 210);
        EXCEPT_NOT_THROW(r.insert_range(cell1, 1), Overlap_Removal::Already_Filled);
        EXCEPT_NOT_THROW(r.insert_range(cell2, 2), Overlap_Removal::Already_Filled);
        EXCEPT_THROW(r.insert_range(cell3, 3), Overlap_Removal::Range_Too_Big);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    { // no fim de um cluster ocupado
        int begin = 0;
        int end = 1899;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(50, 99);
        std::pair<int, int> cell2(200, 299);
        std::pair<int, int> cell3(80, 100);
        EXCEPT_NOT_THROW(r.insert_range(cell1, 1), Overlap_Removal::Already_Filled);
        EXCEPT_NOT_THROW(r.insert_range(cell2, 2), Overlap_Removal::Already_Filled);
        EXCEPT_THROW(r.insert_range(cell3, 3), Overlap_Removal::Already_Filled);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    { // bem no meio de um cluster ocupado
        int begin = 0;
        int end = 1899;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(50, 99);
        std::pair<int, int> cell2(200, 299);
        std::pair<int, int> cell3(230, 250);
        EXCEPT_NOT_THROW(r.insert_range(cell1, 1), Overlap_Removal::Already_Filled);
        EXCEPT_NOT_THROW(r.insert_range(cell2, 2), Overlap_Removal::Already_Filled);
        EXCEPT_THROW(r.insert_range(cell3, 3), Overlap_Removal::Already_Filled);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
}

void Cluster_LegalizationTest::inserir_e_retornar_o_iterador_para_o_cluster()
{
    int begin = 0;
    int end = 1899;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(50, 99);
    Cluster_Iterator theCluster = r.insert_range(cell1, 1);
    QVERIFY(theCluster->has(1));
    QVERIFY(!theCluster->has(2));
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}


void Cluster_LegalizationTest::clusterizar_com_o_cluster_da_direita()
{
    int begin = 0;
    int end = 1899;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(50, 99);
    std::pair<int, int> cell2(100, 299);
    r.insert_range(cell2, 2);
    Cluster_Iterator theCluster = r.insert_range(cell1, 1);
    QVERIFY(theCluster->has(2) && theCluster->has(1));
    QVERIFY(r.number_of_clusters() == 3);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_do_fim_de_um_cluster()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(100, 199);
    std::pair<int, int> cell2(200, 299);
    std::pair<int, int> cell3(300, 399);
    r.insert_range(cell1.first, cell1.second, 1);
    r.insert_range(cell2.first, cell2.second, 2);
    r.insert_range(cell3.first, cell3.second, 3);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    r.remove_by_id(3);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    QVERIFY2(c1.begin() == begin && c1.end() == cell1.first-1, "Primeiro cluster deve começar no início e terminar antes do início da primeira célula");
    QVERIFY2(c2.begin() == cell1.first && c2.end() == cell2.second, "Segundo cluster deve começar no início da primeira célula e terminar no fim da célula do meio");
    QVERIFY2(c3.begin() == cell3.first && c3.end() == end, "Terceiro cluster deve começar depois da célula do meio e terminar no fim");
    QVERIFY2(c1.is_free_space(), "Primeiro cluster deve ser vazio");
    QVERIFY2(!c2.is_free_space(), "Segundo cluster deve ser ocupado");
    QVERIFY2(c3.is_free_space(), "Terceiro cluster deve ser vazio");
    QVERIFY2(c2.number_of_ranges() == 2, "Segundo cluster deve ser ocupado por duas células");
    QVERIFY2(c2.has(1), "Célula 1 deve pertencer ao segundo cluster");
    QVERIFY2(c2.has(2), "Célula 2 deve pertencer ao segundo cluster");
    QVERIFY2(!c2.has(3), "Célula 3 não deve pertencer ao segundo cluster");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_do_inicio_de_um_cluster()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(100, 199);
    std::pair<int, int> cell2(200, 299);
    std::pair<int, int> cell3(300, 399);
    r.insert_range(cell1.first, cell1.second, 1);
    r.insert_range(cell2.first, cell2.second, 2);
    r.insert_range(cell3.first, cell3.second, 3);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    r.remove_by_id(1);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    QVERIFY2(c1.begin() == begin && c1.end() == cell1.second, "Primeiro cluster deve começar no início e terminar no fim da primeira célula (removida)");
    QVERIFY2(c2.begin() == cell2.first && c2.end() == cell3.second, "Segundo cluster deve começar no início da célula do meio e terminar no fim da última célula");
    QVERIFY2(c3.begin() == cell3.second + 1 && c3.end() == end, "Terceiro cluster deve começar depois da última célula e terminar no fim");
    QVERIFY2(c1.is_free_space(), "Primeiro cluster deve ser vazio");
    QVERIFY2(!c2.is_free_space(), "Segundo cluster deve ser ocupado");
    QVERIFY2(c3.is_free_space(), "Terceiro cluster deve ser vazio");
    QVERIFY2(c2.number_of_ranges() == 2, "Segundo cluster deve ser ocupado por duas células");
    QVERIFY2(!c2.has(1), "Célula 1 não deve pertencer ao segundo cluster");
    QVERIFY2(c2.has(2), "Célula 2 deve pertencer ao segundo cluster");
    QVERIFY2(c2.has(3), "Célula 3 deve pertencer ao segundo cluster");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));

}

void Cluster_LegalizationTest::remover_uma_celula_do_meio_de_um_cluster()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(100, 199);
    std::pair<int, int> cell2(200, 299);
    std::pair<int, int> cell3(300, 399);
    r.insert_range(cell1.first, cell1.second, 1);
    r.insert_range(cell2.first, cell2.second, 2);
    r.insert_range(cell3.first, cell3.second, 3);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    r.remove_by_id(2);
    QVERIFY2(r.number_of_clusters() == 5, "Deve ter cinco clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    const Overlap_Removal::Cluster & c4 = r.cluster(3);
    const Overlap_Removal::Cluster & c5 = r.cluster(4);
    QVERIFY2(c1.begin() == begin && c1.end() == cell1.first-1, "Primeiro cluster deve começar no início e terminar antes do início da primeira célula");
    QVERIFY2(c2.begin() == cell1.first && c2.end() == cell1.second, "Segundo cluster deve ser o ocupado pela primeira célula");
    QVERIFY2(c3.begin() == cell2.first && c3.end() == cell2.second, "Terceiro cluster deve ser o range liberado");
    QVERIFY2(c4.begin() == cell3.first && c4.end() == cell3.second, "Quarto cluster deve ser o ocupado pela terceira célula");
    QVERIFY2(c5.begin() == cell3.second + 1 && c5.end() == end, "Quinto cluster deve ser o livre no fim");
    QVERIFY2(c1.is_free_space(), "Primeiro cluster deve ser vazio");
    QVERIFY2(!c2.is_free_space(), "Segundo cluster deve ser ocupado");
    QVERIFY2(c3.is_free_space(), "Terceiro cluster deve ser vazio");
    QVERIFY2(!c4.is_free_space(), "Quarto cluster deve ser ocupado");
    QVERIFY2(c5.is_free_space(), "Quinto cluster deve ser vazio");
    QVERIFY2(c2.number_of_ranges() == 1, "Segundo cluster deve ser ocupado por uma célula");
    QVERIFY2(c4.number_of_ranges() == 1, "Quarto cluster deve ser ocupado por uma célula");
    QVERIFY2(c2.has(1), "Célula 1 deve pertencer ao segundo cluster");
    QVERIFY2(c4.has(3), "Célula 3 deve pertencer ao quarto cluster");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_que_esta_sozinha_no_cluster()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(100, 199);
    r.insert_range(cell1.first, cell1.second, 1);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    r.remove_by_id(1);
    QVERIFY2(r.number_of_clusters() == 1, "Deve ter 1 clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.is_free_space(), "Cluster que sobrou deve estar vazio");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_que_esta_sozinha_em_um_cluster_grudado_no_inicio_da_linha()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 199);
    r.insert_range(cell1, 1);
    r.remove_by_id(1);
    QVERIFY2(r.number_of_clusters() == 1, "Deve ter 1 clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.is_free_space(), "Cluster que sobrou deve estar vazio");
    QVERIFY2(c1.begin() == begin && c1.end() == end, "Cluster que sobrou deve estar vazio e deve ser o único");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_que_esta_sozinha_em_um_cluster_grudado_no_fim_da_linha()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(900, 999);
    r.insert_range(cell1, 1);
    r.remove_by_id(1);
    QVERIFY2(r.number_of_clusters() == 1, "Deve ter 1 clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.is_free_space(), "Cluster que sobrou deve estar vazio");
    QVERIFY2(c1.begin() == begin && c1.end() == end, "Cluster que sobrou deve estar vazio e deve ser o único");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_que_esta_sozinha_em_um_cluster_que_ocupa_toda_a_linha()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(begin, end);
    r.insert_range(cell1, 1);
    r.remove_by_id(1);
    QVERIFY2(r.number_of_clusters() == 1, "Deve ter 1 clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.is_free_space(), "Cluster que sobrou deve estar vazio");
    QVERIFY2(c1.begin() == begin && c1.end() == end, "Cluster que sobrou deve estar vazio e deve ser o único");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_do_inicio_de_um_cluster_grudado_no_inicio_da_linha()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 199);
    std::pair<int, int> cell2(200, 399);

    r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);
    r.remove_by_id(1);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter 1 clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.is_free_space(), "Cluster que sobrou deve estar vazio");
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    QVERIFY2(!c2.is_free_space(), "Cluster que sobrou deve estar ocupado");
    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    QVERIFY2(c3.is_free_space(), "Cluster que sobrou deve estar ocupado");

    QVERIFY(c1.begin() == begin);
    QVERIFY(c1.end() == c2.begin()-1);
    QVERIFY(c2.end() == c3.begin()-1);
    QVERIFY(c3.end() == end);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_do_fim_de_um_cluster_grudado_no_fim_da_linha()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(800, 899);
    std::pair<int, int> cell2(900, 999);

    r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);
    r.remove_by_id(2);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter 1 clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.is_free_space(), "Cluster que sobrou deve estar vazio");
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    QVERIFY2(!c2.is_free_space(), "Cluster que sobrou deve estar ocupado");
    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    QVERIFY2(c3.is_free_space(), "Cluster que sobrou deve estar ocupado");

    QVERIFY(c1.begin() == begin);
    QVERIFY(c1.end() == c2.begin()-1);
    QVERIFY(c2.end() == c3.begin()-1);
    QVERIFY(c3.end() == end);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_do_inicio_de_um_cluster_que_ocupa_toda_a_linha()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(begin, 199);
    std::pair<int, int> cell2(200, end);

    r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);
    r.remove_by_id(1);
    QVERIFY2(r.number_of_clusters() == 2, "Deve ter 2 clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(c1.is_free_space(), "Cluster que sobrou deve estar vazio");
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    QVERIFY2(!c2.is_free_space(), "Cluster que sobrou deve estar ocupado");

    QVERIFY(c1.begin() == begin);
    QVERIFY(c1.end() == c2.begin()-1);
    QVERIFY(c2.end() == end);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_do_fim_de_um_cluster_que_ocupa_toda_a_linha()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(begin, 199);
    std::pair<int, int> cell2(200, end);

    r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);
    r.remove_by_id(2);
    QVERIFY2(r.number_of_clusters() == 2, "Deve ter 2 clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    QVERIFY2(!c1.is_free_space(), "Cluster que sobrou deve estar ocupado");
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    QVERIFY2(c2.is_free_space(), "Cluster que sobrou deve estar vazio");

    QVERIFY(c1.begin() == begin);
    QVERIFY(c1.end() == c2.begin()-1);
    QVERIFY(c2.end() == end);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::remover_uma_celula_do_meio_de_um_cluster_que_ocupa_toda_a_linha()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(begin, 199);
    std::pair<int, int> cell2(200, 299);
    std::pair<int, int> cell3(300, end);
    r.insert_range(cell1.first, cell1.second, 1);
    r.insert_range(cell2.first, cell2.second, 2);
    r.insert_range(cell3.first, cell3.second, 3);
    QVERIFY2(r.number_of_clusters() == 1, "Deve ter um clusters");
    r.remove_by_id(2);
    QVERIFY2(r.number_of_clusters() == 3, "Deve ter três clusters");
    const Overlap_Removal::Cluster & c1 = r.cluster(0);
    const Overlap_Removal::Cluster & c2 = r.cluster(1);
    const Overlap_Removal::Cluster & c3 = r.cluster(2);
    QVERIFY(c1.begin() == begin);
    QVERIFY(c1.end() == c2.begin()-1);
    QVERIFY(c2.end() == c3.begin()-1);
    QVERIFY(c3.end() == end);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_limites_do_cluster()
{
    int begin = 0;
    int end = 999;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(100, 199);
    r.insert_range(cell1.first, cell1.second, 1);
    const Overlap_Removal::Cluster & c = r.cluster(1);
    QVERIFY(c.begin() == cell1.first);
    QVERIFY(c.end() == cell1.second);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}



void Cluster_LegalizationTest::obter_posicoes_mais_proximas_passando_por_cima_de_ranges_ocupados()
{
    { // Só antes
        int begin = -1000;
        int end = 510;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(100, 299);
        std::pair<int, int> cell2(341, 499);
        std::pair<int, int> cell3(450, 499);
        r.insert_range(cell1.first, cell1.second, 1);
        r.insert_range(cell2.first, cell2.second, 2);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell3);
        QVERIFY(nearests.first.first->end() == cell1.first - 1);
        QVERIFY(nearests.second.first == r.not_valid_iterator());
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    { // Só depois
        int begin = 0;
        int end = 1500;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(100, 299);
        std::pair<int, int> cell2(400, 499);
        std::pair<int, int> cell3(900, 999);
        std::pair<int, int> cell4(110, 399);
        r.insert_range(cell1.first, cell1.second, 1);
        r.insert_range(cell2.first, cell2.second, 2);
        r.insert_range(cell3.first, cell3.second, 3);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell4);
        QVERIFY(nearests.first.first == r.not_valid_iterator());
        QVERIFY(nearests.second.first->begin() == 500);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    { // Antes e Depois
        int begin = -1000;
        int end = 1500;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(100, 299);
        std::pair<int, int> cell2(400, 499);
        std::pair<int, int> cell3(900, 999);
        std::pair<int, int> cell4(110, 399);
        r.insert_range(cell1.first, cell1.second, 1);
        r.insert_range(cell2.first, cell2.second, 2);
        r.insert_range(cell3.first, cell3.second, 3);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell4);
        QVERIFY(nearests.first.first->end() == cell1.first - 1);
        QVERIFY(nearests.second.first->begin() == 500);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    { // Não tem
        int begin = 0;
        int end = 600;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(100, 299);
        std::pair<int, int> cell2(400, 499);
        std::pair<int, int> cell3(511, 599);
        std::pair<int, int> cell4(110, 399);
        r.insert_range(cell1.first, cell1.second, 1);
        r.insert_range(cell2.first, cell2.second, 2);
        r.insert_range(cell3.first, cell3.second, 3);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell4);
        QVERIFY(nearests.first.first == nearests.second.first);
        QVERIFY(nearests.second.first == r.not_valid_iterator());
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_se_a_celula_comeca_antes_e_termina_depois_de_um_cluster()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, 239);
    std::pair<int, int> cell2(180, 279);
    r.insert_range(cell1, 1);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
    QVERIFY(nearests.first.first->end() == cell1.first - 1);
    QVERIFY(nearests.second.first->begin() == cell1.second + 1);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_se_a_celula_cabe_inteira_dentro_de_um_cluster()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, 239);
    std::pair<int, int> cell2(210, 229);
    r.insert_range(cell1, 1);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
    QVERIFY(nearests.first.first->end() == cell1.first - 1);
    QVERIFY(nearests.second.first->begin() == cell1.second + 1);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_se_a_celula_ocupa_o_mesmo_espaco_do_cluster()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, 239);
    std::pair<int, int> cell2(200, 239);
    r.insert_range(cell1, 1);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
    QVERIFY(nearests.first.first->end() == cell1.first - 1);
    QVERIFY(nearests.second.first->begin() == cell1.second + 1);
    QVERIFY(nearests.first.first->has_capacity(cell2.second-cell2.first+1));
    QVERIFY(nearests.second.first->has_capacity(cell2.second-cell2.first+1));
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_se_a_celula_tem_o_mesmo_tamanho_do_cluster()
{
    {
        int begin = -1000;
        int end = 1000;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(200, 239);
        std::pair<int, int> cell2(220, 259);
        r.insert_range(cell1, 1);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
        QVERIFY(nearests.first.first->end() == cell1.first - 1);
        QVERIFY(nearests.second.first->begin() == cell1.second + 1);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    {
        int begin = -1000;
        int end = 1000;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(200, 239);
        std::pair<int, int> cell2(180, 219);
        r.insert_range(cell1, 1);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
        QVERIFY(nearests.first.first->end() == cell1.first - 1);
        QVERIFY(nearests.second.first->begin() == cell1.second + 1);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
}

void Cluster_LegalizationTest::obter_posicao_mais_proxima_se_a_celula_cabe_onde_quer_entrar()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, 239);
    std::pair<int, int> cell2(300, 399);
    r.insert_range(cell1, 1);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
    QVERIFY(nearests.first.first == nearests.second.first);
    QVERIFY(nearests.first.first->begin() <= cell2.first);
    QVERIFY(nearests.first.first->end() >= cell2.second);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_posicao_mais_proxima_se_a_celula_cabe_certinho_no_cluster_da_esquerda()
{
    int begin = 0;
    int end = 100;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(24, 100);
    std::pair<int, int> cell2(2, 25);
    r.insert_range(cell1, 1);
    std::pair<std::pair<Cluster_Iterator, int>, std::pair<Cluster_Iterator, int> > next = r.get_previous_and_next_free(cell2.first, cell2.second);
    QVERIFY(next.first.second == 0);
    QVERIFY(next.first.first->has_capacity(cell2.second-cell2.first+1));
    QVERIFY(next.first.first->is_free_space());
    QVERIFY(next.first.first->begin() == begin && next.first.first->end() == cell1.first-1);

    r.insert_range_in_cluster(next.first.first, std::make_pair(next.first.second, cell2.second-cell2.first), 2);
    QVERIFY(r.number_of_clusters() == 1);

}

void Cluster_LegalizationTest::obter_posicao_mais_proxima_se_a_celula_cabe_certinho_no_cluster_da_direita()
{
    int begin = 0;
    int end = 100;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 76);
    std::pair<int, int> cell2(75, 98);
    r.insert_range(cell1, 1);
    std::pair<std::pair<Cluster_Iterator, int>, std::pair<Cluster_Iterator, int> > next = r.get_previous_and_next_free(cell2.first, cell2.second);
    QVERIFY(next.second.second == 77);
    QVERIFY(next.second.first->has_capacity(cell2.second-cell2.first+1));
    QVERIFY(next.second.first->is_free_space());
    QVERIFY(next.second.first->begin() == cell1.second+1 && next.second.first->end() == end);

    r.insert_range_in_cluster(next.second.first, std::make_pair(next.second.second, next.second.second+cell2.second-cell2.first), 2);
    QVERIFY(r.number_of_clusters() == 1);
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_do_espaco_livre_permitindo_x_porcento_de_overlap()
{
    int begin = -1000;
    int end = 1000;
    double ratio = 0.75;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(100, 199);
    std::pair<int, int> cell2(300, 399);
    std::pair<int, int> cell3(200, 319);
    r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell3, ratio);
    QVERIFY(nearests.first.first == nearests.second.first);
    QVERIFY(nearests.first.first->begin() == cell3.first);
    QVERIFY(nearests.first.first->end() <= cell3.second);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_do_espaco_livre_permitindo_x_porcento_de_overlap_movendo_no_maximo_um_cluster()
{
    int begin = 0;
    int end = 30;
    double ratio = 0.6;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 7);
    std::pair<int, int> cell2(14, 14);
    std::pair<int, int> cell3(16, 16);
    std::pair<int, int> cell4(8, 17);

    r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);
    r.insert_range(cell3, 3);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell4, ratio);
    QVERIFY(nearests.first.first == r.not_valid_iterator());
    QVERIFY(nearests.second.first->begin() == cell3.second+1);
    QVERIFY(nearests.second.second == cell3.second+1);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_do_espaco_ocupado_permitindo_x_porcento_de_overlap()
{
    int begin = -1000;
    int end = 1000;
    double ratio = 0.75;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(100, 199);
    std::pair<int, int> cell2(197, 499);
    r.insert_range(cell1, 1);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2, ratio);
    QVERIFY(nearests.first.first == nearests.second.first);
    QVERIFY(nearests.first.first->begin() == cell1.first);
    QVERIFY(nearests.first.first->end() <= cell1.second);
    QVERIFY(nearests.first.second == cell2.first);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_do_espaco_ocupado_permitindo_x_porcento_de_overlap_movendo_no_maximo_um_cluster()
{
    int begin = 0;
    int end = 30;
    double ratio = 0.6;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 7);
    std::pair<int, int> cell2(14, 14);
    std::pair<int, int> cell3(16, 16);
    std::pair<int, int> cell4(7, 16);

    r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);
    r.insert_range(cell3, 3);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell4, ratio);
    QVERIFY(nearests.first.first == r.not_valid_iterator());
    QVERIFY(nearests.second.first->begin() == cell3.second+1);
    QVERIFY(nearests.second.second == cell3.second+1);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_do_espaco_ocupado_permitindo_x_porcento_de_overlap_movendo_no_maximo_um_cluster_com_overlap_antes_e_depois()
{
    int begin = -10;
    int end = 100;
    double ratio = 0.6;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 7);
    std::pair<int, int> cell2(16, 30);
    std::pair<int, int> cell3(7, 16);

    r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);
    std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell3, ratio);
    QVERIFY(nearests.first.first->begin() == cell1.first);
    QVERIFY(nearests.second.first == nearests.first.first);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::mover_um_cluster_para_direita_e_nao_clusterizar()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, 239);
    std::pair<int, int> cell2(250, 269);
    Cluster_Iterator first_cluster = r.insert_range(cell1, 1);
    Cluster_Iterator second_cluster = r.insert_range(cell2, 2);

    int step = 4;
    first_cluster = r.move_cluster_to_right(first_cluster, step);
    QVERIFY(first_cluster->has(1));
    QVERIFY(!first_cluster->has(2));
    QVERIFY(first_cluster->begin() == cell1.first + step);
    QVERIFY(first_cluster->end() == cell1.second + step);
    QVERIFY2(&(*first_cluster) != &(*second_cluster), "Não pode clusterizar!");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::mover_um_cluster_para_direita_e_clusterizar()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, 239);
    std::pair<int, int> cell2(250, 269);
    Cluster_Iterator the_cluster = r.insert_range(cell1, 1);
    r.insert_range(cell2, 2);

    int step = 10;
    the_cluster = r.move_cluster_to_right(the_cluster, step);
    QVERIFY(r.number_of_clusters() == 3);
    QVERIFY(the_cluster->has(1));
    QVERIFY(the_cluster->has(2));
    QVERIFY(the_cluster->begin() == cell1.first + step);
    QVERIFY(the_cluster->end() == cell2.second);
    QVERIFY(the_cluster->number_of_ranges() == 2);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::mover_um_cluster_para_esquerda_e_nao_clusterizar()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, 239);
    std::pair<int, int> cell2(250, 269);
    Cluster_Iterator first_cluster = r.insert_range(cell1, 1);
    Cluster_Iterator second_cluster = r.insert_range(cell2, 2);

    int step = 4;
    second_cluster = r.move_cluster_to_left(second_cluster, step);
    QVERIFY(first_cluster->has(1));
    QVERIFY(!first_cluster->has(2));
    QVERIFY(second_cluster->begin() == cell2.first - step);
    QVERIFY(second_cluster->end() == cell2.second - step);
    QVERIFY2(&(*first_cluster) != &(*second_cluster), "Não pode clusterizar!");
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::mover_um_cluster_para_esquerda_e_clusterizar()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, 239);
    std::pair<int, int> cell2(250, 269);
    Cluster_Iterator the_cluster = r.insert_range(cell1, 1);
    the_cluster = r.insert_range(cell2, 2);

    int step = 10;
    the_cluster = r.move_cluster_to_left(the_cluster, step);
    QVERIFY(r.number_of_clusters() == 3);
    QVERIFY(the_cluster->has(1));
    QVERIFY(the_cluster->has(2));
    QVERIFY(the_cluster->begin() == cell1.first);
    QVERIFY(the_cluster->end() == cell2.second - step);
    QVERIFY(the_cluster->number_of_ranges() == 2);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::mover_o_cluster_do_fim_para_a_esquerda()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(200, end);
    Cluster_Iterator the_cluster = r.insert_range(cell1, 1);
    r.move_cluster_to_left(the_cluster, 10);

    QVERIFY(r.number_of_clusters() == 3);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::mover_o_cluster_do_inicio_para_a_direita()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(begin, 200);
    Cluster_Iterator the_cluster = r.insert_range(cell1, 1);
    r.move_cluster_to_right(the_cluster, 10);

    QVERIFY(r.number_of_clusters() == 3);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::impedir_que_mova_um_cluster_para_a_direita_no_limite_da_linha()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(900, 1000);
    Cluster_Iterator the_cluster = r.insert_range(cell1, 1);
    EXCEPT_THROW(r.move_cluster_to_right(the_cluster, 10), Overlap_Removal::Not_Enough_Space);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::impedir_que_mova_um_cluster_para_a_esquerda_no_inicio_da_linha()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(-1000, 100);
    Cluster_Iterator the_cluster = r.insert_range(cell1, 1);
    EXCEPT_THROW(r.move_cluster_to_left(the_cluster, 1), Overlap_Removal::Not_Enough_Space);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::impedir_que_tente_mover_um_cluster_com_um_passo_menor_que_1()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 100);
    Cluster_Iterator the_cluster = r.insert_range(cell1, 1);
    EXCEPT_THROW(the_cluster = r.move_cluster_to_left(the_cluster, 0), Overlap_Removal::Invalid_Step_Size);
    EXCEPT_THROW(the_cluster = r.move_cluster_to_left(the_cluster, -1), Overlap_Removal::Invalid_Step_Size);
    EXCEPT_NOT_THROW(the_cluster = r.move_cluster_to_left(the_cluster, 1), Overlap_Removal::Invalid_Step_Size);

    EXCEPT_THROW(the_cluster = r.move_cluster_to_right(the_cluster, 0), Overlap_Removal::Invalid_Step_Size);
    EXCEPT_THROW(the_cluster = r.move_cluster_to_right(the_cluster, -1), Overlap_Removal::Invalid_Step_Size);
    EXCEPT_NOT_THROW(the_cluster = r.move_cluster_to_right(the_cluster, 1), Overlap_Removal::Invalid_Step_Size);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::impedir_que_mova_para_a_direita_sem_espaco_livre()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 100);
    std::pair<int, int> cell2(110, 200);
    Cluster_Iterator first_cluster = r.insert_range(cell1, 1);
    Cluster_Iterator second_cluster = r.insert_range(cell2, 2);
    EXCEPT_THROW(first_cluster = r.move_cluster_to_right(first_cluster, 10), Overlap_Removal::Not_Enough_Space);
    EXCEPT_NOT_THROW(first_cluster = r.move_cluster_to_right(first_cluster, 9), Overlap_Removal::Not_Enough_Space);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));

}

void Cluster_LegalizationTest::impedir_que_mova_para_a_esquerda_sem_espaco_livre()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 100);
    std::pair<int, int> cell2(110, 200);
    Cluster_Iterator first_cluster = r.insert_range(cell1, 1);
    Cluster_Iterator second_cluster = r.insert_range(cell2, 2);
    EXCEPT_THROW(second_cluster = r.move_cluster_to_left(second_cluster, 10), Overlap_Removal::Not_Enough_Space);
    EXCEPT_NOT_THROW(second_cluster = r.move_cluster_to_left(second_cluster, 9), Overlap_Removal::Not_Enough_Space);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::impedir_que_mova_um_cluster_livre()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 100);
    Cluster_Iterator first_cluster = r.insert_range(cell1, 1);
    first_cluster--;
    EXCEPT_THROW(r.move_cluster_to_right(first_cluster, 10), Overlap_Removal::Forbidden_Operation);
    EXCEPT_THROW(r.move_cluster_to_left(first_cluster, 10), Overlap_Removal::Forbidden_Operation);
}

void Cluster_LegalizationTest::encontrando_um_cluster_com_base_em_um_range()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 100);
    std::pair<int, int> cell2(90, 200);
    Cluster_Iterator first_cluster = r.insert_range(cell1, 1);
    Cluster_Iterator the_cluster = r.find_cluster_by_range(cell1);
    QVERIFY(&(*the_cluster) == &(*first_cluster));
    the_cluster = r.find_cluster_by_range(cell2);
    QVERIFY(the_cluster == first_cluster);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));

}

void Cluster_LegalizationTest::encontrando_um_cluster_com_base_em_uma_coordenada()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    std::pair<int, int> cell1(0, 100);
    Cluster_Iterator first_cluster = r.insert_range(cell1, 1);
    for(int i = begin; i <= end; i++)
    {
        Cluster_Iterator the_cluster = r.find_cluster_by_value(i);
        if(i >= cell1.first && i <= cell1.second)
            QVERIFY(&(*the_cluster) == &(*first_cluster));
        else
            QVERIFY(&(*the_cluster) != &(*first_cluster));
    }
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::criar_um_range_invalido()
{
    int begin = -1000;
    int end = 1000;
    Overlap_Removal::Row r(begin, end);
    EXCEPT_THROW(r.insert_range(10, 4, 6), Overlap_Removal::Invalid_Range);
    EXCEPT_THROW(r = Overlap_Removal::Row(1000, 999), Overlap_Removal::Invalid_Range);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::mover_um_cluster_sem_precisar_passar_por_todos_do_cluster()
{
    Overlap_Removal::Row r(0, 1000);
    std::pair<int, int> cell1(500, 599);
    Cluster_Iterator cluster = r.insert_range(cell1, 1);
    cluster = r.move_cluster_to_right(cluster, 20);
    int last_end = cluster->begin() - 1;
    for(std::list<Overlap_Removal::Range_In_Cluster>::iterator it = cluster->ranges().begin(); it != cluster->ranges().end(); it++)
        QVERIFY(it->begin() == last_end+1);
    QVERIFY(cluster->begin() == 500+20);
    QVERIFY(cluster->end() == 599+20);
    QVERIFY(cluster->ranges().front().begin() == cluster->begin());
    QVERIFY(cluster->ranges().back().end() == cluster->end());
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::referencia_range_para_cluster()
{
    Overlap_Removal::Row r(0, 1000);
    std::pair<int, int> cell1(500, 599);
    Cluster_Iterator cluster = r.insert_range(cell1, 1);
    Overlap_Removal::Range_In_Cluster & range = cluster->ranges().front();
    QVERIFY(range.cluster() == cluster);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::clone_de_linha()
{
    Overlap_Removal::Row r(0, 1000);
    std::pair<int, int> cell1(500, 599);
    Cluster_Iterator cluster = r.insert_range(cell1, 1);

    Overlap_Removal::Row r2(r);

    QVERIFY(r2.number_of_clusters() == r.number_of_clusters());
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r2));

}

void Cluster_LegalizationTest::insercao_em_um_cluster_especifico()
{
    Overlap_Removal::Row r(0, 1000);
    std::pair<int, int> cell1(500, 599);
    Cluster_Iterator cluster = r.insert_range(cell1, 1);
    cluster++;
    QVERIFY(cluster->is_free_space());
    r.insert_range_in_cluster(cluster, std::make_pair(620, 800), 2);
    QVERIFY(r.number_of_clusters() == 5);
    QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
}

void Cluster_LegalizationTest::espaco_a_direita()
{
    Overlap_Removal::Row r(0, 1000);
    std::pair<int, int> cell1(500, 599);
    Cluster_Iterator cluster = r.insert_range(cell1, 1);
    QVERIFY(r.free_space_on_right(cluster) == 401);

    cluster  = r.move_cluster_to_right(cluster, 50);
    QVERIFY(r.free_space_on_right(cluster) == 351);
}

void Cluster_LegalizationTest::espaco_a_esquerda()
{
    Overlap_Removal::Row r(0, 1000);
    std::pair<int, int> cell1(500, 599);
    Cluster_Iterator cluster = r.insert_range(cell1, 1);
    QVERIFY(r.free_space_on_left(cluster) == 500);

    cluster  = r.move_cluster_to_left(cluster, 50);
    QVERIFY(r.free_space_on_left(cluster) == 450);
}

void Cluster_LegalizationTest::espaco_total_a_esquerda()
{
    Overlap_Removal::Row r(0, 1000);
    std::pair<int, int> cell1(500, 599);

    std::pair<int, int> cell2(800, 859);

    Cluster_Iterator cluster = r.insert_range(cell1, 1);
    Cluster_Iterator cluster2 = r.insert_range(cell2, 2);

    QVERIFY(r.total_free_space_on_left(cluster, cluster->begin()) == 500);
    QVERIFY(r.total_free_space_on_left(cluster2, cluster->begin()) == 700);
}

void Cluster_LegalizationTest::espaco_total_a_direita()
{
    Overlap_Removal::Row r(0, 1000);
    std::pair<int, int> cell1(500, 599);

    std::pair<int, int> cell2(800, 859);

    Cluster_Iterator cluster = r.insert_range(cell1, 1);
    Cluster_Iterator cluster2 = r.insert_range(cell2, 2);

    QVERIFY(r.total_free_space_on_right(cluster, cluster->end()) == 341);
    QVERIFY(r.total_free_space_on_right(cluster2, cluster->end()) == 141);

}

void Cluster_LegalizationTest::encontrar_celulas_da_direita_e_esquerda()
{
    ///-----aaa[bbbb]bbcccddeee----  | 1 - quebra A para esquerda e B pra direita
    ///-----aaab[bbbb]bcccddeee----  | 2 - tenta trocar pela B
    ///-----aaabb[bbbb]cccddeee----  | 3 - quebra B pra esquerda e C pra direita
    ///-----aaabbb[bbbc]ccddeee----  | 4 - quebra B pra esquerda e C pra direita
    ///-----aaabbbb[bbcc]cddeee----  | 5 - quebra B pra esquerda e C pra direita
    ///-----aaabbbbb[bccc]ddeee----  | 6 - quebra B pra esquerda e C pra direita
    ///-----aaabbbbbb[cccd]deee----  | 7 - quebra C pra esquerda e D pra direita
    ///-----aaabbbbbbc[ccdd]eee----  | 8 - quebra C pra esquerda e D pra direita
    ///-----aaabbbbbbcc[cdde]ee----  | 9 - tenta trocar com a D
    ///-----aaabbbbbbccc[ddee]e----  | 10 - quebra D pra esquerda e E pra direita
    ///-----aaabbbbbbcccd[deee]----  | 11 - quebra D pra esquerda e E pra direita
    ///-----aaabbbbbbcccdd[eee-]---  | 12 - não quebra
    ///-----aa[abbb]bbbcccddeee----  | 13 - quebra A para esquerda e B pra direita
    ///-----a[aabb]bbbbcccddeee----  | 14 - quebra A para esquerda e B pra direita
    ///-----[aaab]bbbbbcccddeee----  | 15 - quebra A para esquerda e B pra direita
    ///----[-aaa]bbbbbbcccddeee----  | 16 - não quebra
    Overlap_Removal::Row r(0, 279);
    std::pair<int, int> cellA(50, 79);
    std::pair<int, int> cellB(80, 139);
    std::pair<int, int> cellC(140, 169);
    std::pair<int, int> cellD(170, 189);
    std::pair<int, int> cellE(190, 219);

    r.insert_range(cellA, 0);
    r.insert_range(cellB, 1);
    r.insert_range(cellC, 2);
    r.insert_range(cellD, 3);
    r.insert_range(cellE, 4);

    std::pair<int, int> caso1(80, 119);
    std::pair<int, int> caso2(90, 129);
    std::pair<int, int> caso3(100, 139);
    std::pair<int, int> caso4(110, 149);
    std::pair<int, int> caso5(120, 159);
    std::pair<int, int> caso6(130, 169);
    std::pair<int, int> caso7(140, 179);
    std::pair<int, int> caso8(150, 189);
    std::pair<int, int> caso9(160, 199);
    std::pair<int, int> caso10(170, 209);
    std::pair<int, int> caso11(180, 219);
    std::pair<int, int> caso12(190, 229);
    std::pair<int, int> caso13(70, 109);
    std::pair<int, int> caso14(60, 99);
    std::pair<int, int> caso15(50, 89);
    std::pair<int, int> caso16(40, 79);



    //    std::cout << "[";
    //    char current = 'a';
    //    for(Cluster_Iterator the_cluster = r.first_cluster_iterator(); the_cluster != r.not_valid_iterator(); the_cluster++)
    //    {
    //        if(the_cluster->is_free_space())
    //        {
    //            for(int i = 0; i < the_cluster->end()-the_cluster->begin()+1; i+=10)
    //                std::cout << "_";
    //        }
    //        else {
    //            for(std::list<Overlap_Removal::Range_In_Cluster>::const_iterator the_range = the_cluster->ranges().begin(); the_range != the_cluster->ranges().end(); the_range++)
    //            {
    //                for(int i = 0; i < the_range->end()-the_range->begin()+1; i+= 10)
    //                    std::cout << current;
    //                current++;
    //                std::cout << ";";
    //            }
    //        }
    //    }
    //    std::cout << "]" << std::endl;

    Cluster_Iterator the_cluster(r.first_cluster_iterator());
    the_cluster++;

    QVERIFY(r.first_range_at_left_of(caso1) == 0);
    QVERIFY(r.first_range_at_left_of(caso2) == 0);
    QVERIFY(r.first_range_at_left_of(caso3) == 1);
    QVERIFY(r.first_range_at_left_of(caso4) == 1);
    QVERIFY(r.first_range_at_left_of(caso5) == 1);
    QVERIFY(r.first_range_at_left_of(caso6) == 1);
    QVERIFY(r.first_range_at_left_of(caso7) == 2);
    QVERIFY(r.first_range_at_left_of(caso8) == 2);
    QVERIFY(r.first_range_at_left_of(caso9) == 2);
    QVERIFY(r.first_range_at_left_of(caso10) == 3);
    QVERIFY(r.first_range_at_left_of(caso11) == 3);
    QVERIFY(r.first_range_at_left_of(caso12) == 4);
    QVERIFY(r.first_range_at_left_of(caso13) == 0);
    QVERIFY(r.first_range_at_left_of(caso14) == 0);
    QVERIFY(r.first_range_at_left_of(caso15) == 0);
    QVERIFY(r.first_range_at_left_of(caso16) == -1);


    QVERIFY(r.first_range_at_right_of(caso1) == 1);
    QVERIFY(r.first_range_at_right_of(caso2) == 2);
    QVERIFY(r.first_range_at_right_of(caso3) == 2);
    QVERIFY(r.first_range_at_right_of(caso4) == 2);
    QVERIFY(r.first_range_at_right_of(caso5) == 2);
    QVERIFY(r.first_range_at_right_of(caso6) == 2);
    QVERIFY(r.first_range_at_right_of(caso7) == 3);
    QVERIFY(r.first_range_at_right_of(caso8) == 3);
    QVERIFY(r.first_range_at_right_of(caso9) == 4);
    QVERIFY(r.first_range_at_right_of(caso10) == 4);
    QVERIFY(r.first_range_at_right_of(caso11) == 4);
    QVERIFY(r.first_range_at_right_of(caso12) == -1);
    QVERIFY(r.first_range_at_right_of(caso13) == 1);
    QVERIFY(r.first_range_at_right_of(caso14) == 1);
    QVERIFY(r.first_range_at_right_of(caso15) == 1);
    QVERIFY(r.first_range_at_right_of(caso16) == 0);
}

void Cluster_LegalizationTest::encontrar_celulas_da_direita_e_esquerda2()
{
    {// CASO1: range totalmente interno a um cluster livre
        Overlap_Removal::Row r(0, 279);
        std::pair<int, int> cellA(50, 79);
        std::pair<int, int> cellB(100, 139);
        r.insert_range(cellA, 0);
        r.insert_range(cellB, 1);
        std::pair<int, int> range(90, 95);
        QVERIFY(r.first_range_at_left_of(range) == 0);
        QVERIFY(r.first_range_at_right_of(range) == 1);
    }

    {// CASO2: range "overlappa" dois clusters (um no início e um no fim)
        Overlap_Removal::Row r(0, 279);
        std::pair<int, int> cellA(50, 79);
        std::pair<int, int> cellB(100, 139);
        r.insert_range(cellA, 0);
        r.insert_range(cellB, 1);
        std::pair<int, int> range(70, 109);
        QVERIFY(r.first_range_at_left_of(range) == 0);
        QVERIFY(r.first_range_at_right_of(range) == 1);
    }

    {// CASO3: range "overlappa" só um cluster no início
        Overlap_Removal::Row r(0, 279);
        std::pair<int, int> cellA(50, 79);
        std::pair<int, int> cellB(100, 139);
        r.insert_range(cellA, 0);
        r.insert_range(cellB, 1);
        std::pair<int, int> range(70, 89);
        QVERIFY(r.first_range_at_left_of(range) == 0);
        QVERIFY(r.first_range_at_right_of(range) == 1);
    }

    {// CASO4: range "overlappa" só um cluster no fim
        Overlap_Removal::Row r(0, 279);
        std::pair<int, int> cellA(50, 79);
        std::pair<int, int> cellB(100, 139);
        r.insert_range(cellA, 0);
        r.insert_range(cellB, 1);
        std::pair<int, int> range(90, 138);
        QVERIFY(r.first_range_at_left_of(range) == 0);
        QVERIFY(r.first_range_at_right_of(range) == 1);
    }

    {// CASO5: range está totalmente dentro de um cluster ocupado
        Overlap_Removal::Row r(-1000, 1000);
        std::pair<int, int> cellA(0, 69);
        std::pair<int, int> cellB(70, 279);
        r.insert_range(cellA, 0);
        r.insert_range(cellB, 1);
        std::pair<int, int> range(120, 269);
        QVERIFY(r.first_range_at_left_of(range) == 1);
        QVERIFY(r.first_range_at_right_of(range) == -1);
    }


    {// CASO6: range está totalmente dentro de um cluster ocupado, mas a célula da esquerda está em outro cluster
        Overlap_Removal::Row r(-1000, 1000);
        std::pair<int, int> cellA(0, 69);
        std::pair<int, int> cellB(90, 279);
        r.insert_range(cellA, 0);
        r.insert_range(cellB, 1);
        std::pair<int, int> range(90, 100);
        QVERIFY(r.first_range_at_left_of(range) == 0);
        QVERIFY(r.first_range_at_right_of(range) == 1);
    }

    {// CASO7: range está totalmente dentro de um cluster ocupado, mas a célula da direita está em outro cluster
        Overlap_Removal::Row r(-1000, 1000);
        std::pair<int, int> cellA(0, 69);
        std::pair<int, int> cellB(90, 279);
        r.insert_range(cellA, 0);
        r.insert_range(cellB, 1);
        std::pair<int, int> range(50, 69);
        QVERIFY(r.first_range_at_left_of(range) == 0);
        QVERIFY(r.first_range_at_right_of(range) == 1);
    }

    {// CASO8: range "overlappa" três clusters
        Overlap_Removal::Row r(-1000, 1000);

        std::pair<int, int> cellAa(0, 9);
        std::pair<int, int> cellAb(10, 29);
        std::pair<int, int> cellAc(30, 39);
        std::pair<int, int> cellAd(40, 59);

        std::pair<int, int> cellBa(90, 99);
        std::pair<int, int> cellBb(100, 119);

        std::pair<int, int> cellCa(140, 159);
        std::pair<int, int> cellCb(160, 199);

        r.insert_range(cellAa, 0);
        r.insert_range(cellAb, 1);
        r.insert_range(cellAc, 2);
        r.insert_range(cellAd, 3);

        r.insert_range(cellBa, 4);
        r.insert_range(cellBb, 5);

        r.insert_range(cellCa, 6);
        r.insert_range(cellCb, 7);

        std::pair<int, int> range(50, 149);

        QVERIFY(r.first_range_at_left_of(range) == 4);
        QVERIFY(r.first_range_at_right_of(range) == 5);

    }

}

void Cluster_LegalizationTest::__print_row(Overlap_Removal::Row & r, int resolution)
{
//    std::cout << "[";
//    for(Cluster_Iterator the_cluster = r.first_cluster_iterator(); the_cluster != r.not_valid_iterator(); the_cluster++)
//    {
//        if(the_cluster->is_free_space())
//        {
//            for(int i = 0; i < the_cluster->end()-the_cluster->begin()+1; i+=resolution)
//                std::cout << "_";
//        }
//        else {
//            for(std::list<Overlap_Removal::Range_In_Cluster>::const_iterator the_range = the_cluster->ranges().begin(); the_range != the_cluster->ranges().end(); the_range++)
//            {
//                for(int i = 0; i < the_range->end()-the_range->begin()+1; i+= resolution)
//                    std::cout << char(int('a')+the_range->id());
//            }
//        }
//    }
//    std::cout << "]" << std::endl;
}

void Cluster_LegalizationTest::quebrar_cluster()
{
    Overlap_Removal::Row r(-100, 279);
    // aaabbbbbbcccddeee
    // aa|abb|bbbbcccddeee
    std::pair<int, int> cellA(0, 29);
    std::pair<int, int> cellB(30, 89);
    std::pair<int, int> cellC(90, 119);
    std::pair<int, int> cellD(120, 139);
    std::pair<int, int> cellE(140, 169);

    r.insert_range(cellA, 0);
    r.insert_range(cellB, 1);
    r.insert_range(cellC, 2);
    r.insert_range(cellD, 3);
    r.insert_range(cellE, 4);

    std::pair<int, int> range(20, 49);
    QVERIFY(r.free_space() >= range.second-range.first+1);

    __print_row(r);

    int step = 50;
    int left = r.first_range_at_left_of(range);
    Cluster_Iterator left_cluster = r.find_cluster_by_id(left);
    int overlap_begin = std::max(range.first, left_cluster->begin());
    int overlap_end = overlap_begin+1;
    for(std::list<Overlap_Removal::Range_In_Cluster>::const_iterator the_range = left_cluster->ranges().begin(); the_range != left_cluster->ranges().end(); the_range++)
    {
        if(the_range->id() == left)
        {
            overlap_end = std::min(the_range->end(), range.second);
            break;
        }
    }
    int overlap_size = overlap_end-overlap_begin+1;
    step = std::min(r.free_space_on_left(left_cluster), overlap_size);
    left_cluster = r.split_cluster_and_move_to_left(left_cluster, left, step);
    __print_row(r);

    int right = r.first_range_at_right_of(range);
    Cluster_Iterator right_cluster = r.find_cluster_by_id(right);
    overlap_begin = std::max(range.first, right_cluster->begin());
    overlap_end = overlap_begin+1;
    for(std::list<Overlap_Removal::Range_In_Cluster>::const_iterator the_range = right_cluster->ranges().begin(); the_range != right_cluster->ranges().end(); the_range++)
    {
        if(the_range->id() == right)
        {
            overlap_end = std::min(the_range->end(), range.second);
            break;
        }
    }
    overlap_size = overlap_end-overlap_begin+1;
    step = std::min(r.free_space_on_right(right_cluster), overlap_size);
    right_cluster = r.split_cluster_and_move_to_right(right_cluster, right, step);

    __print_row(r);
    r.insert_range(range, 5);

    __print_row(r);


    QVERIFY(r.number_of_clusters() == 3);

}

void Cluster_LegalizationTest::espaco_livre_na_linha()
{
    Overlap_Removal::Row r(-100, 279);
    QVERIFY(r.free_space() == r.end()-r.begin()+1);
    r.insert_range(std::make_pair(-100, -1), 0);
    QVERIFY(r.free_space() == 280);
}

void Cluster_LegalizationTest::inserir_range_movendo_os_outros_se_necessario()
{
    {
        Overlap_Removal::Row r(-1000, 1000);

        std::pair<int, int> cellAa(0, 9);
        std::pair<int, int> cellAb(10, 29);
        std::pair<int, int> cellAc(30, 39);
        std::pair<int, int> cellAd(40, 59);

        std::pair<int, int> cellBa(90, 99);
        std::pair<int, int> cellBb(100, 119);

        std::pair<int, int> cellCa(140, 159);
        std::pair<int, int> cellCb(160, 199);

        r.insert_range(cellAa, 0);
        r.insert_range(cellAb, 1);
        r.insert_range(cellAc, 2);
        r.insert_range(cellAd, 3);

        r.insert_range(cellBa, 4);
        r.insert_range(cellBb, 5);

        r.insert_range(cellCa, 6);
        r.insert_range(cellCb, 7);

        __print_row(r);
        Overlap_Removal::Insert_Range_Moving_The_Others insert;
        QVERIFY(insert(std::make_pair(50, 1000), 8, r));
        //    QVERIFY(insert(std::make_pair(50, 149), 8, r));
        __print_row(r);
    }

    {
        Overlap_Removal::Row r(-1000, 1000);

        std::pair<int, int> cellAa(0, 9);
        std::pair<int, int> cellAb(10, 29);
        std::pair<int, int> cellAc(30, 39);
        std::pair<int, int> cellAd(40, 59);

        std::pair<int, int> cellBa(90, 99);
        std::pair<int, int> cellBb(100, 119);

        std::pair<int, int> cellCa(140, 159);
        std::pair<int, int> cellCb(160, 199);

        r.insert_range(cellAa, 0);
        r.insert_range(cellAb, 1);
        r.insert_range(cellAc, 2);
        r.insert_range(cellAd, 3);

        r.insert_range(cellBa, 4);
        r.insert_range(cellBb, 5);

        r.insert_range(cellCa, 6);
        r.insert_range(cellCb, 7);

        __print_row(r);
        Overlap_Removal::Insert_Range_Moving_The_Others insert;
        QVERIFY(insert(std::make_pair(-800, 85), 8, r));
        //    QVERIFY(insert(std::make_pair(50, 149), 8, r));
        __print_row(r);
    }
}

void Cluster_LegalizationTest::inserir_range_movendo_os_outros_se_necessario_no_limite_de_espaco()
{
    Overlap_Removal::Row r(-20, 229);

    std::pair<int, int> cellAa(0, 9);
    std::pair<int, int> cellAb(10, 29);
    std::pair<int, int> cellAc(30, 39);
    std::pair<int, int> cellAd(40, 59);

    std::pair<int, int> cellBa(90, 99);
    std::pair<int, int> cellBb(100, 119);

    std::pair<int, int> cellCa(140, 159);
    std::pair<int, int> cellCb(160, 199);

    r.insert_range(cellAa, 0);
    r.insert_range(cellAb, 1);
    r.insert_range(cellAc, 2);
    r.insert_range(cellAd, 3);

    r.insert_range(cellBa, 4);
    r.insert_range(cellBb, 5);

    r.insert_range(cellCa, 6);
    r.insert_range(cellCb, 7);

    __print_row(r);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(insert(std::make_pair(50, 149), 8, r));
    //    QVERIFY(insert(std::make_pair(50, 149), 8, r));
    __print_row(r);
    QVERIFY(r.number_of_clusters() == 1);
}

void Cluster_LegalizationTest::inserir_range_movendo_os_outros_se_necessario_no_limite_de_faltando_1_na_direita()
{
    Overlap_Removal::Row r(-20, 228);

    std::pair<int, int> cellAa(0, 9);
    std::pair<int, int> cellAb(10, 29);
    std::pair<int, int> cellAc(30, 39);
    std::pair<int, int> cellAd(40, 59);

    std::pair<int, int> cellBa(90, 99);
    std::pair<int, int> cellBb(100, 119);

    std::pair<int, int> cellCa(140, 159);
    std::pair<int, int> cellCb(160, 199);

    r.insert_range(cellAa, 0);
    r.insert_range(cellAb, 1);
    r.insert_range(cellAc, 2);
    r.insert_range(cellAd, 3);

    r.insert_range(cellBa, 4);
    r.insert_range(cellBb, 5);

    r.insert_range(cellCa, 6);
    r.insert_range(cellCb, 7);



    __print_row(r);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(!insert(std::make_pair(50, 149), 8, r));
    //    QVERIFY(insert(std::make_pair(50, 149), 8, r));
    __print_row(r);
    QVERIFY(r.number_of_clusters() == 7);
}

void Cluster_LegalizationTest::inserir_range_movendo_os_outros_se_necessario_no_limite_de_faltando_1_na_esquerda()
{
    Overlap_Removal::Row r(-19, 229);

    std::pair<int, int> cellAa(0, 9);
    std::pair<int, int> cellAb(10, 29);
    std::pair<int, int> cellAc(30, 39);
    std::pair<int, int> cellAd(40, 59);

    std::pair<int, int> cellBa(90, 99);
    std::pair<int, int> cellBb(100, 119);

    std::pair<int, int> cellCa(140, 159);
    std::pair<int, int> cellCb(160, 199);

    r.insert_range(cellAa, 0);
    r.insert_range(cellAb, 1);
    r.insert_range(cellAc, 2);
    r.insert_range(cellAd, 3);

    r.insert_range(cellBa, 4);
    r.insert_range(cellBb, 5);

    r.insert_range(cellCa, 6);
    r.insert_range(cellCb, 7);



    __print_row(r);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(!insert(std::make_pair(50, 149), 8, r));
    //    QVERIFY(insert(std::make_pair(50, 149), 8, r));
    __print_row(r);
    QVERIFY(r.number_of_clusters() == 7);
}

void Cluster_LegalizationTest::inserir_range_movendo_os_outros_se_necessario_no_limite_de_faltando_1_em_cada_lado()
{
    Overlap_Removal::Row r(-19, 228);

    std::pair<int, int> cellAa(0, 9);
    std::pair<int, int> cellAb(10, 29);
    std::pair<int, int> cellAc(30, 39);
    std::pair<int, int> cellAd(40, 59);

    std::pair<int, int> cellBa(90, 99);
    std::pair<int, int> cellBb(100, 119);

    std::pair<int, int> cellCa(140, 159);
    std::pair<int, int> cellCb(160, 199);

    r.insert_range(cellAa, 0);
    r.insert_range(cellAb, 1);
    r.insert_range(cellAc, 2);
    r.insert_range(cellAd, 3);

    r.insert_range(cellBa, 4);
    r.insert_range(cellBb, 5);

    r.insert_range(cellCa, 6);
    r.insert_range(cellCb, 7);


    __print_row(r);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(!insert(std::make_pair(50, 149), 8, r));
    //    QVERIFY(insert(std::make_pair(50, 149), 8, r));
    __print_row(r);
    QVERIFY(r.number_of_clusters() == 7);
}

void Cluster_LegalizationTest::inserir_range_movendo_os_outros_se_necessario_o_range_eh_o_menor()
{
    Overlap_Removal::Row r(-19, 228);
    std::pair<int, int> cellAa(20, 43);
    std::pair<int, int> cellBa(52, 83);

    r.insert_range(cellAa, 0);
    r.insert_range(cellBa, 1);

    __print_row(r);
    std::pair<int, int> range(32, 39);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(insert(range, 2, r));
    __print_row(r);
}

void Cluster_LegalizationTest::inserir_range_movendo_os_outros_se_necessario_o_range_eh_o_menor2()
{
    Overlap_Removal::Row r(-19, 228);
    std::pair<int, int> cellA(9, 32);

    std::pair<int, int> cellBa(34, 36);
    std::pair<int, int> cellBb(37, 52);

    r.insert_range(cellA, 0);
    r.insert_range(cellBa, 1);
    r.insert_range(cellBb, 2);

    __print_row(r, 2);
    std::pair<int, int> range(32, 39);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(insert(range, 3, r));
    __print_row(r, 2);
}

void Cluster_LegalizationTest::inserir_range_movendo_os_outros_soh_para_a_direita()
{
    Overlap_Removal::Row r(-19, 228);
    std::pair<int, int> cellAa(0, 23);
    std::pair<int, int> cellAb(24, 71);

    std::pair<int, int> range(24, 35);

    r.insert_range(cellAa, 0);
    r.insert_range(cellAb, 1);

    __print_row(r, 2);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(insert(range, 2, r));
    __print_row(r, 2);

    QVERIFY(r.number_of_clusters() == 3);

}

void Cluster_LegalizationTest::mover_soh_para_a_esquerda_no_fim_da_linha()
{
    Overlap_Removal::Row r(8181, 8280);
    std::pair<int, int> cellAa(8230, 8253);
    std::pair<int, int> cellAb(8254, 8277);
//    std::pair<int, int> cellB(8181, 8200);

    r.insert_range(cellAa, 0);
    r.insert_range(cellAb, 1);

//    r.insert_range(cellB, 3);

    std::pair<int, int> range(8246, 8270);

    __print_row(r, 2);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(insert(range, 2, r));
    __print_row(r, 2);

    QVERIFY(r.number_of_clusters() == 3);
    QVERIFY(r.cluster(1).begin() == 8198);
    QVERIFY(r.cluster(1).end() == range.second);
}

void Cluster_LegalizationTest::mover_soh_para_a_esquerda_no_fim_da_linha_quebrando()
{
    Overlap_Removal::Row r(8181, 8280);
    std::pair<int, int> cellAa(8230, 8253);
    std::pair<int, int> cellAb(8254, 8266);
    std::pair<int, int> cellAc(8267, 8267);
    std::pair<int, int> cellAd(8268, 8269);
    std::pair<int, int> cellAe(8270, 8272);

    std::pair<int, int> cellBa(8275, 8276);

    r.insert_range(cellAa, 0);
    r.insert_range(cellAb, 1);
    r.insert_range(cellAc, 2);
    r.insert_range(cellAd, 3);
    r.insert_range(cellAe, 4);

    r.insert_range(cellBa, 5);

    std::pair<int, int> range(8246, 8270);

    __print_row(r, 2);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(insert(range, 6, r));
    __print_row(r, 2);

    QVERIFY(r.number_of_clusters() == 3);
}

void Cluster_LegalizationTest::mover_soh_para_a_direita_no_inicio_da_linha()
{
    Overlap_Removal::Row r(8181, 8280);
    std::pair<int, int> cellAa(8190, 8213);
    std::pair<int, int> cellAb(8214, 8237);

    r.insert_range(cellAa, 0);
    r.insert_range(cellAb, 1);

    std::pair<int, int> range(8197, 8221);

    __print_row(r, 2);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(insert(range, 2, r));
    __print_row(r, 2);

    QVERIFY(r.number_of_clusters() == 3);
    QVERIFY(r.cluster(1).begin() == range.first);
}

void Cluster_LegalizationTest::mover_soh_para_a_direita_no_inicio_da_linha_quebrando()
{
    Overlap_Removal::Row r(8181, 8280);
    std::pair<int, int> cellAa(8185, 8186);

    std::pair<int, int> cellBa(8189, 8191);
    std::pair<int, int> cellBb(8192, 8193);
    std::pair<int, int> cellBc(8194, 8194);
    std::pair<int, int> cellBd(8195, 8207);
    std::pair<int, int> cellBe(8208, 8231);

    r.insert_range(cellAa, 0);

    r.insert_range(cellBa, 1);
    r.insert_range(cellBb, 2);
    r.insert_range(cellBc, 3);
    r.insert_range(cellBd, 4);
    r.insert_range(cellBe, 5);

    std::pair<int, int> range(8191, 8215);

    __print_row(r, 2);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(insert(range, 6, r));
    __print_row(r, 2);

    QVERIFY(r.number_of_clusters() == 3);
}

void Cluster_LegalizationTest::mover_soh_para_a_direita_mantendo_um_na_esquerda_no_inicio_da_linha()
{
    Overlap_Removal::Row r(8181, 8280);
    std::pair<int, int> cellAa(8183, 8184);

    std::pair<int, int> cellBa(8186, 8194);
    std::pair<int, int> cellBb(8195, 8207);
    std::pair<int, int> cellBc(8208, 8231);

    std::pair<int, int> cellCa(8261, 8280);


    r.insert_range(cellAa, 0);

    r.insert_range(cellBa, 1);
    r.insert_range(cellBb, 2);
    r.insert_range(cellBc, 3);

    r.insert_range(cellCa, 4);

    std::pair<int, int> range(8191, 8215);

    __print_row(r, 2);
    Overlap_Removal::Insert_Range_Moving_The_Others insert;
    QVERIFY(!insert(range, 5, r));

    r.remove_by_id(4);

    QVERIFY(insert(range, 5, r));

    __print_row(r, 2);

}

void Cluster_LegalizationTest::obter_posicoes_mais_proximas_sem_passar_por_cima()
{
    { // Só antes
        int begin = 0;
        int end = 610;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(500, 599);
        std::pair<int, int> cell2(581, 680);
        r.insert_range(cell1.first, cell1.second, 1);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
        QVERIFY(nearests.first.first->end() == cell1.first - 1);
        QVERIFY(nearests.second.first == r.not_valid_iterator());
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }

    { // Só depois
        int begin = 450;
        int end = 1000;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(500, 599);
        std::pair<int, int> cell2(581, 680);
        r.insert_range(cell1.first, cell1.second, 1);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
        QVERIFY(nearests.first.first == r.not_valid_iterator());
        QVERIFY(nearests.second.first->begin() == cell1.second + 1);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    { // Antes e depois
        int begin = -1000;
        int end = 1000;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(500, 599);
        std::pair<int, int> cell2(581, 680);
        r.insert_range(cell1.first, cell1.second, 1);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
        QVERIFY(nearests.first.first->end() == cell1.first - 1);
        QVERIFY(nearests.second.first->begin() == cell1.second + 1);
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }
    { // Não tem
        int begin = 450;
        int end = 650;
        Overlap_Removal::Row r(begin, end);
        std::pair<int, int> cell1(500, 599);
        std::pair<int, int> cell2(581, 680);
        r.insert_range(cell1.first, cell1.second, 1);
        std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > nearests = r.get_previous_and_next_free(cell2);
        QVERIFY(nearests.first.first == nearests.second.first);
        QVERIFY(nearests.second.first == r.not_valid_iterator());
        QVERIFY(verifica_se_todos_os_ranges_estao_com_referencias_para_seus_clusters(r));
    }

}

QTEST_APPLESS_MAIN(Cluster_LegalizationTest)

#include "tst_cluster_legalizationtest.moc"

