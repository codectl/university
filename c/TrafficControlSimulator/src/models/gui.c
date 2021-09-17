#include <stdlib.h>

#include <allegro5/allegro.h>

#include "structs.h"
#include "airport.h"

const float PATTERN_SIZE_X = 640;
const float PATTERN_SIZE_Y = 480;
const float FPS = 60;

void display_gui(AIRPORT *airport){

	// allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	bool running = true;
	bool redraw = true;

	// Initialize allegro
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro.\n");
		exit(1);
	}

    airport_toString(airport);
    /* convert nmi's into pixels */
    int convert_x = PATTERN_SIZE_X/airport->x;
    int convert_y = PATTERN_SIZE_Y/airport->y;

	// Initialize the timer
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "Failed to create timer.\n");
		exit(1);
	}

	// Create the display
	display = al_create_display(640, 480);
	if (!display) {
		fprintf(stderr, "Failed to create display.\n");
		exit(1);
	}

	// Create the event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create event queue.");
		exit(1);
	}

	// Register event sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	// Display a black screen
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	// Start the timer
	al_start_timer(timer);

	// Game loop
    while (running) {
        ALLEGRO_EVENT event;
        ALLEGRO_TIMEOUT timeout;

        // Initialize timeout
        al_init_timeout(&timeout, 0.06);

        // Fetch the event (if one exists)
        bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);

        // Handle the event
        if (get_event) {
            switch (event.type) {
                case ALLEGRO_EVENT_TIMER:
                    redraw = true;
                    break;
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    running = false;
                    break;
                default:
                    fprintf(stderr, "Unsupported event received: %d\n", event.type);
                    break;
            }
        }

        // Check if we need to redraw
        if (redraw && al_is_event_queue_empty(event_queue)) {
            // Redraw
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_flip_display();
            redraw = false;
        }
    }

    // Clean up
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

//	set_gfx_mode(GFX_AUTODETECT_WINDOWED, PATTERN_SIZE_X, PATTERN_SIZE_Y, 0, 0);
//	rectfill(screen, 0, 0, PATTERN_SIZE_X, PATTERN_SIZE_Y, airport->color);  /* Background color */

//	/* Drawing the runway */
//	for (i=0; i<airport->n_runways; i++){
//		rectfill(screen, airport->runways[i]->x0 * convert_x, airport->runways[i]->y0 * convert_y - airport->runways[i]->width/2,
//			airport->runways[i]->x1 * convert_x, airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2, airport->runways[i]->color);
//		if(airport->runways[i]->x1 > airport->runways[i]->x0){ /* orientation of the runway comes from the left */
//			for(j=0; j<airport->runways[i]->n_marks; j++)
//				circlefill(screen, airport->runways[i]->x0 * convert_x - convert_x * (j+1), airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2, airport->runways[i]->width/2, 1); /* Runway approaching marks */
//			line(screen, airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow,
//			     airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2,
//			     (airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5,
//			     (airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5)), 1);
//			line(screen, airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow,
//			     airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2,
//			     (airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5,
//			     (airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2) + ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5)), 1);
//
//
//			/* Details about the runway */
//			text = create_bitmap(PATTERN_SIZE_X, PATTERN_SIZE_X);
//			clear(text);
//			textprintf_centre_ex(text, font, airport->runways[i]->x1 * convert_x + convert_x,
//				airport->runways[i]->y1 * convert_y, 7, -1, "R%d:%d/%d", airport->runways[i]->id, airport->runways[i]->alt, airport->runways[i]->spd);
//			pivot_sprite(screen, text, airport->runways[i]->x1 * convert_x + convert_x,
//				airport->runways[i]->y1 * convert_y,
//				airport->runways[i]->x1 * convert_x + convert_x,
//				airport->runways[i]->y1 * convert_y + convert_y, itofix(64));
//			clear(text);
//			textprintf_centre_ex(text, font, airport->runways[i]->x0 * convert_x - airport->runways[i]->mark_arrow * convert_x,
//				airport->runways[i]->y0 * convert_y, 7, -1, "ALT:3000  SPD:200");
//			pivot_sprite(screen, text, airport->runways[i]->x0 * convert_x - airport->runways[i]->mark_arrow * convert_x,
//				airport->runways[i]->y0 * convert_y,
//				airport->runways[i]->x0 * convert_x - airport->runways[i]->mark_arrow * convert_x,
//				airport->runways[i]->y0 * convert_y + convert_y, itofix(64));
//
//
//		}
//		else{ /* orientation of the runway comes from the right */
//			for(j=0; j<airport->runways[i]->n_marks; j++)
//				circlefill(screen, airport->runways[i]->x0 * convert_x + convert_x * (j+1), airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2, airport->runways[i]->width/2, 1);
//			line(screen, airport->runways[i]->x0 * convert_x + convert_x * airport->runways[i]->mark_arrow,
//			     airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2,
//			     (airport->runways[i]->x0 * convert_x + convert_x * airport->runways[i]->mark_arrow) + convert_x * 1.5,
//			     (airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5)), 1);
//			line(screen, airport->runways[i]->x0 * convert_x + convert_x * airport->runways[i]->mark_arrow,
//			     airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2,
//			     (airport->runways[i]->x0 * convert_x + convert_x * airport->runways[i]->mark_arrow) + convert_x * 1.5,
//			     (airport->runways[i]->y0 * convert_y + airport->runways[i]->width/2) + ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - ((airport->runways[i]->x0 * convert_x - convert_x * airport->runways[i]->mark_arrow) - convert_x * 1.5)), 1);
//		}
//	}
//
//	/* Drawing GATES */
//	for (i=0; i<airport->n_gates; i++){
//		rectfill(screen, airport->gates[i]->position_x * convert_x, airport->gates[i]->position_y * convert_y,
//			 airport->gates[i]->position_x * convert_x + airport->gates[i]->size * convert_x,
//			 airport->gates[i]->position_y * convert_y + airport->gates[i]->width * convert_y,
//			 airport->gates[i]->color);
//
//		if(airport->gates[i]->width > airport->gates[i]->size){
//			text = create_bitmap(PATTERN_SIZE_X, PATTERN_SIZE_X);
//			clear(text);
//			if(airport->gates[i]->type == 'A'){
//				textprintf_centre_ex(text, font, airport->gates[i]->position_x * convert_x,
//					(airport->gates[i]->position_y * convert_y) + (airport->gates[i]->width/2) * convert_y,
//					7, -1, "AR%d; %d/%d", airport->gates[i]->number,
//					airport->gates[i]->alt, airport->gates[i]->spd);
//			}
//			else
//				textprintf_centre_ex(text, font, airport->gates[i]->position_x * convert_x,
//					(airport->gates[i]->position_y * convert_y) + (airport->gates[i]->width/2) * convert_y,
//					7, -1, "DEP%d; %d/%d", airport->gates[i]->number,
//					airport->gates[i]->alt, airport->gates[i]->spd);
//		 	pivot_sprite(screen, text, airport->gates[i]->position_x * convert_x,
//				    (airport->gates[i]->position_y * convert_y),
//				    airport->gates[i]->position_x * convert_x - airport->gates[i]->size/2 * convert_x * 0.75,
//				    (airport->gates[i]->position_y * convert_y) + (airport->gates[i]->width) * convert_y * airport->gates[i]->size * 0.7, itofix(64));
//		}
//		else{
//			if(airport->gates[i]->type == 'A')
//				textprintf_centre_ex(screen, font, airport->gates[i]->position_x * convert_x + airport->gates[i]->size/2 * convert_x,
//						(airport->gates[i]->position_y * convert_y - convert_y * 0.75),
//						7, -1, "AR%d; %d/%d", airport->gates[i]->number,
//						airport->gates[i]->alt, airport->gates[i]->spd);
//
//			else
//				textprintf_centre_ex(screen, font, airport->gates[i]->position_x * convert_x + airport->gates[i]->size/2 * convert_x,
//						(airport->gates[i]->position_y * convert_y - convert_y * 0.75),
//						7, -1, "DEP%d; %d/%d", airport->gates[i]->number,
//						airport->gates[i]->alt, airport->gates[i]->spd);
//		}
//
//		/* Drawing points */
//		for (j=0; j<airport->gates[i]->n_points * 2; j+=2){
//			if (j>0)
//				line(screen, airport->gates[i]->points[j] * convert_x,
//				airport->gates[i]->points[j+1] * convert_y,
//				airport->gates[i]->points[j-2] * convert_x,
//				airport->gates[i]->points[j-1] * convert_y, 9);
//			else{
//				if(airport->gates[i]->width > airport->gates[i]->size){
//					line(screen, closest_distance(airport->gates[i]->position_x, airport->gates[i]->position_x + airport->gates[i]->size, airport->gates[i]->points[j]) * convert_x,
//					(airport->gates[i]->position_y * convert_y) + (airport->gates[i]->width/2) * convert_y,
//					airport->gates[i]->points[j] * convert_x,
//					airport->gates[i]->points[j+1] * convert_y, 9);
//
//				}
//
//				else{
//					line(screen, (airport->gates[i]->position_x * convert_x) + (airport->gates[i]->size/2) * convert_x,
//					closest_distance(airport->gates[i]->position_y, airport->gates[i]->position_y + airport->gates[i]->width, airport->gates[i]->points[j+1]) * convert_y,
//					airport->gates[i]->points[j] * convert_x,
//					airport->gates[i]->points[j+1] * convert_y, 9);
//				}
//			}
//			circlefill(screen, airport->gates[i]->points[j] * convert_x,
//				  airport->gates[i]->points[j+1] * convert_y, convert_y/2, 9);
//		}
//	}

//	while (!key[KEY_ESC]){
//		if(mouse_b & 1) break;
//	}
}
