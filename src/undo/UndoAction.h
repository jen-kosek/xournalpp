/*
 * Xournal++
 *
 * Abstract undo action
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "model/PageRef.h"

#include <config.h>

#include <vector>
using std::vector;

class Control;
class XojPage;

class UndoAction
{
public:
	UndoAction(const char* className);
	virtual ~UndoAction();

public:
	virtual bool undo(Control* control) = 0;
	virtual bool redo(Control* control) = 0;

	virtual string getText() = 0;

	/**
	 * Get the affected pages
	 */
	virtual vector<XojPage*> getPages();

	const char* getClassName() const;

protected:
	XOJ_TYPE_ATTRIB;

	// This is only for debugging / Testing purpose
	const char* className;

	PageRef page;
	bool undone;
};
