#include "common/common.h"

#include <stdio.h>
void 		display_sections(const t_segment *s)
{
	while (s)
	{
		printf("SEGMENT %s\n", s->name);
		const t_section *sec = (const t_section*)s->sections.begin;
		for (uint32_t i = 0; i < s->sections.nelems; ++i)
			printf(" - Section %s\n", sec[i].name);
		s = s->next;
	}
}
