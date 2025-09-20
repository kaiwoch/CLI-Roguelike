#include "Interectable.h"
#include "Inventory.h"

#pragma once

class Door : public Interectable {
public:	
	Door();
	void Open(Inventory& inventory);
};