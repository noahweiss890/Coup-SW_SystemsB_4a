#include <iostream>
#include <stdexcept>
#include "doctest.h"

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace std;
using namespace coup;

TEST_CASE("checking game winner") {
    Game g;
    Duke duke{g, "Ross"};
	Assassin assassin{g, "Rachel"};

    CHECK_THROWS(g.winner());

    // cout << "HEYYYY" << endl;

    duke.tax();
    assassin.income();
    duke.tax();
    assassin.income();
    duke.tax();
    assassin.income();

    duke.coup(assassin);

    CHECK(g.winner() == "Ross");
}

TEST_CASE("checking turn order") {
    Game g;
    Duke duke{g, "p1"};
	Assassin assassin{g, "p2"};
	Ambassador ambassador{g, "p3"};
	Captain captain{g, "p4"};
	Contessa contessa{g, "p5"};

    CHECK(g.turn() == "p1");
    duke.income();
    CHECK(g.turn() == "p2");
    assassin.income();
    CHECK(g.turn() == "p3");
    ambassador.income();
    CHECK(g.turn() == "p4");
    captain.income();
    CHECK(g.turn() == "p5");
    contessa.income();
    CHECK(g.turn() == "p1");
    
    CHECK_THROWS(captain.income());
}

TEST_CASE("checking basic actions") {
    Game g;
    Duke duke{g, "p1"};
	Captain captain{g, "p2"};

    CHECK(duke.coins() == 0);
    duke.income();
    CHECK(duke.coins() == 1);

    CHECK(captain.coins() == 0);
    captain.foreign_aid();
    CHECK(captain.coins() == 2);

    duke.income();
    captain.foreign_aid();
    duke.income();
    captain.foreign_aid();
    duke.income();
    captain.foreign_aid();
    duke.income();

    captain.coup(duke);
}

TEST_CASE("checking role method") {
    Game g;
    Duke duke{g, "p1"};
	Assassin assassin{g, "p2"};
	Ambassador ambassador{g, "p3"};
	Captain captain{g, "p4"};
	Contessa contessa{g, "p5"};

    CHECK(duke.role() == "Duke");
    CHECK(assassin.role() == "Assassin");
    CHECK(ambassador.role() == "Ambassador");
    CHECK(captain.role() == "Captain");
    CHECK(contessa.role() == "Contessa");
}

TEST_CASE("checking players method") {
    Game g;
    Duke duke{g, "p1"};
	Assassin assassin{g, "p2"};
	Ambassador ambassador{g, "p3"};
	Captain captain{g, "p4"};
	Contessa contessa{g, "p5"};

    vector<string> players = g.players();
    CHECK(players.size() == 5);
    CHECK(players.at(0) == "p1");
    CHECK(players.at(1) == "p2");
    CHECK(players.at(2) == "p3");
    CHECK(players.at(3) == "p4");
    CHECK(players.at(4) == "p5");
}

TEST_CASE("checking coins method") {
    Game g;
    Duke duke{g, "p1"};
	Assassin assassin{g, "p2"};
	Ambassador ambassador{g, "p3"};
	Captain captain{g, "p4"};
	Contessa contessa{g, "p5"};

    CHECK(duke.coins() == 0);
    duke.tax();
    CHECK(duke.coins() == 3);

    CHECK(assassin.coins() == 0);
    assassin.foreign_aid();
    CHECK(assassin.coins() == 2);

    CHECK(ambassador.coins() == 0);
    ambassador.income();
    CHECK(ambassador.coins() == 1);

    CHECK(captain.coins() == 0);
    captain.steal(duke);
    CHECK(captain.coins() == 2);
    CHECK(duke.coins() == 1);
}

TEST_CASE("checking if 10+ coins must coup") {
    Game g;
    Duke duke{g, "p1"};
	Contessa contessa{g, "p2"};

    duke.tax();
    contessa.income();
    duke.tax();
    contessa.income();
    duke.tax();
    contessa.income();
    duke.tax();
    contessa.income();

    CHECK_THROWS(duke.income());
    CHECK_THROWS(duke.foreign_aid());
    CHECK_THROWS(duke.tax());
}

TEST_CASE("checking if not enough coins to coup") {
    Game g;
    Duke duke{g, "p1"};
    Assassin assassin{g, "p2"};

    duke.income();
    assassin.income();

    CHECK_THROWS(duke.coup(assassin));

    duke.income();
    assassin.income();
    duke.income();
    assassin.income();
    duke.income();
    CHECK_NOTHROW(assassin.coup(duke));
}

TEST_CASE("checking blocked too late") {
    Game g;
    Contessa contessa{g, "p1"};
    Duke duke{g, "p2"};

    contessa.foreign_aid();
    duke.income();
    CHECK(g.turn() == "p1");
    CHECK_THROWS(duke.block(contessa));
}

TEST_CASE("checking duke") {
    Game g;
    Duke duke{g, "p1"};
	Contessa contessa{g, "p2"};

    CHECK_THROWS(duke.block(contessa));
    
    CHECK(duke.coins() == 0);
    duke.tax();
    CHECK(duke.coins() == 3);

    contessa.foreign_aid();

    CHECK_NOTHROW(duke.block(contessa));
}

TEST_CASE("checking assassin") {
    Game g;
    Assassin assassin{g, "p1"};
	Captain captain{g, "p2"};
    
    assassin.foreign_aid();
    captain.income();
    assassin.income();

    CHECK_NOTHROW(assassin.coup(captain));
    vector<string> players = g.players();
    CHECK(players.size() == 1);
}

TEST_CASE("checking ambassador") {
    Game g;
    Duke duke{g, "p1"};
    Ambassador ambassador{g, "p2"};
	Captain captain{g, "p3"};
    
    CHECK_THROWS(ambassador.block(duke));

    duke.tax();

    CHECK_THROWS(ambassador.transfer(captain, duke));

    CHECK(duke.coins() == 3);
    CHECK(captain.coins() == 0);

    ambassador.transfer(duke, captain);

    CHECK(duke.coins() == 2);
    CHECK(captain.coins() == 1);

    captain.income();
    duke.income();
    ambassador.foreign_aid();

    CHECK(ambassador.coins() == 2);
    CHECK(captain.coins() == 2);

    captain.steal(ambassador);

    CHECK(ambassador.coins() == 0);
    CHECK(captain.coins() == 4);

    ambassador.block(captain);

    CHECK(ambassador.coins() == 2);
    CHECK(captain.coins() == 2);
}

TEST_CASE("checking captain") {
    Game g;
    Duke duke{g, "p1"};
	Captain captain1{g, "p2"};
	Captain captain2{g, "p3"};

    CHECK_THROWS(captain1.block(duke));

    duke.income();

    CHECK_THROWS(captain1.steal(duke));

    captain1.income();
    captain2.income();
    duke.income();
    captain1.steal(duke);

    CHECK(duke.coins() == 0);
    CHECK(captain1.coins() == 3);

    captain2.steal(captain1);

    CHECK(captain1.coins() == 1);
    CHECK(captain1.coins() == 3);

    CHECK_NOTHROW(captain1.block(captain2));

    CHECK(captain1.coins() == 3);
    CHECK(captain1.coins() == 1);
}

TEST_CASE("checking contessa") {
    Game g;
    Assassin assassin{g, "p1"};
	Contessa contessa{g, "p2"};

    CHECK_THROWS(contessa.block(assassin));

    assassin.foreign_aid();
    contessa.income();
    assassin.foreign_aid();
    contessa.income();
    assassin.coup(contessa);
    CHECK_NOTHROW(contessa.block(assassin));
}