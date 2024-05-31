#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void 
packet_handler (u_char *args, const struct pcap_pkthdr* header, const u_char* packet)
{
	printf("Received a packet of length %d\n", header->len);
}

int 
main (void)
{
	pcap_t* handle;
	char errbuf[PCAP_ERRBUF_SIZE];

	handle = pcap_open_live("iwm0", BUFSIZ, 1, 1000, errbuf);
	if (handle == NULL) {
		fprintf(stderr, "Was not able to open interface: %s\n", errbuf);
		return 1;
	}

	pcap_loop  (handle, 0, packet_handler, NULL);
	pcap_close (handle);
	return 0;
}
